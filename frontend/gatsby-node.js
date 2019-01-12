const _ = require('lodash');
const path = require('path');
const Promise = require('bluebird');
const PurgeCssPlugin = require(`purgecss-webpack-plugin`);
const glob = require(`glob`);
const { createFilePath } = require(`gatsby-source-filesystem`);
const { fmImagesToRelative } = require('gatsby-remark-relative-images');
const routes = require('./src/meta/routes');
const componentWithMDXScope = require("gatsby-mdx/component-with-mdx-scope");


const PATHS = {
  src: path.join(__dirname, `src`)
}

const SLUG_SEPARATOR = '___';

exports.onCreateBabelConfig = ({ actions: { setBabelPlugin } }) => {
  setBabelPlugin({
    name: 'babel-plugin-tailwind-components',
    options: {
      config: './tailwind.js',
      format: 'auto'
    }
  })
};


exports.onCreateNode = ({ node, getNode, actions }) => {
  const { createNodeField } = actions;

  /* dumb hack */
  const prevType = node.internal.type;
  // console.log("before node = %j", node);
  node.internal.type = (node.internal.type === `MarkdownRemark` || node.internal.type === `Mdx`) ? "MarkdownRemark" : prevType;
  fmImagesToRelative(node);
  node.internal.type = prevType;
  // console.log("after node = %j", node);

  if (node.internal.type === `MarkdownRemark` || node.internal.type === `Mdx`) {
    const fileNode = getNode(node.parent);
    const filePath = createFilePath({ node, getNode });
    const source = fileNode.sourceInstanceName;

    const separatorExists = ~filePath.indexOf(SLUG_SEPARATOR);

    let slug;
    let prefix;

    if (separatorExists) {
      const separatorPosition = filePath.indexOf(SLUG_SEPARATOR);
      const slugBeginning = separatorPosition + SLUG_SEPARATOR.length;
      slug = (separatorPosition === 1 ? null : `/${filePath.substring(slugBeginning)}`);
      prefix = filePath.substring(1, separatorPosition);
    } else {
      slug = filePath;
      prefix = '';
    }

    // hmm look at this
    // if (source !== 'parts') {
      createNodeField({
        node,
        name: `slug`,
        value: slug,
      });
    // }
    createNodeField({
      node,
      name: `prefix`,
      value: prefix,
    });
    createNodeField({
      node,
      name: `source`,
      value: source,
    });
  }
};

exports.createPages = ({ graphql, actions }) => {
  const { createPage } = actions;

  return new Promise((resolve, reject) => {
    const categoryTemplate = path.resolve('./src/templates/CategoryTemplate.js');

    resolve(
      graphql(`
        {
          allMdx(
            filter: { fields: { slug: { ne: null } } }
            sort: { fields: [fields___prefix], order: DESC }
            limit: 1000
          ) {
            edges {
              node {
                rawBody
                code {
                  scope
                  body
                }
                tableOfContents
                fileAbsolutePath
                fields {
                  slug
                  prefix
                  source
                }
                frontmatter {
                  title
                  categories
                }
              }
            }
          }
        }
      `).then(result => {
          if (result.errors) {
            console.log(result.errors);
            reject(result.errors);
          }

          const items = result.data.allMdx.edges;
          const categorySet = new Set();

          // Create category list
          items.forEach(edge => {
            const {
              node: {
                frontmatter: { categories },
              },
            } = edge;

            if (categories) {
              categories.forEach(category => {
                categorySet.add(category);
              });
            }
          });

          // Create category pages
          const categoryList = Array.from(categorySet);
          categoryList.forEach(category => {
            createPage({
              path: `/categories/${_.kebabCase(category)}/`,
              component:
                componentWithMDXScope(
                  categoryTemplate,
                  undefined /* TODO ?????? category .MD? */
                ),
              context: {
                category,
              },
            });
          });

          routes.routesArray.filter((route) => route.template).map((route) => {
            const srcPath = route.dir || route.path;
            const edges = items.filter(item => item.node.fields.source === (srcPath));

            edges.forEach((edge, index) => {
              createPage({
                path: `${route.path}${edge.node.fields.slug}`,
                component:
                  componentWithMDXScope(route.template, edge.node.code.scope),
                context: {
                  id: edge.node.id,
                  ...(route.context ? route.context(edge, index, edges) : {})
                },
              });
            });
          })
        })
    );
  });
};

const purgeCssConfig = {
  paths: glob.sync(`${PATHS.src}/**/*.js`, { nodir: true }),
  extractors: [
    {
      // Custom extractor to allow special characters (like ":") in class names
      // See: https://tailwindcss.com/docs/controlling-file-size/#removing-unused-css-with-purgecss
      extractor: class {
        static extract(content) {
          return content.match(/[A-Za-z0-9-_:/]+/g) || []
        }
      },
      extensions: [`js`]
    }
  ],
  whitelist: [`class-to-whitelist`], // adjust for each project
  whitelistPatterns: [/body/, /headroom/, /ReactModal/, /ril/] // adjust for each project
};

exports.onCreateWebpackConfig = ({ actions, stage }) => {
  if (stage.includes(`develop`)) return

  // Add PurgeCSS in production
  // See: https://github.com/gatsbyjs/gatsby/issues/5778#issuecomment-402481270
  if (stage.includes(`build`)) {
    actions.setWebpackConfig({
      plugins: [new PurgeCssPlugin(purgeCssConfig)]
    })
  }
}