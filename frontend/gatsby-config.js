require('dotenv').config();
const config = require('./src/meta/config');
const routes = require('./src/meta/routes');

let cmsUploadCMSName = "uploads";

const gatsbyNetlifyCMSPaths = {
  resolve: `gatsby-plugin-netlify-cms-paths`,
  options: {
    // Path to your Netlify CMS config file
    cmsConfig: `/static/admin/config.yml`
  }
};

const subRemarkPlugins = [
  gatsbyNetlifyCMSPaths,
  {
    resolve: `gatsby-remark-relative-images`,
    options: {
      name: cmsUploadCMSName
    }
  },
  {
    resolve: 'gatsby-remark-images',
    options: {
      maxWidth: 690,
      linkImagesToOriginal: false,
    },
  },
  {
    resolve: `gatsby-remark-prismjs`,
  },
  {
    resolve: `gatsby-remark-responsive-iframe`,
  },
  {
    resolve: `gatsby-remark-copy-linked-files`,
  },
  {
    resolve: `gatsby-remark-smartypants`,
  },
  {
    resolve: 'gatsby-remark-emojis',
    options: {
      // Deactivate the plugin globally (default: true)
      active: true,
      // Add a custom css class
      class: 'emoji-icon',
      // Select the size (available size: 16, 24, 32, 64)
      size: 64,
      // Add custom styles
      styles: {
        display: 'inline',
        margin: '0',
        'margin-top': '1px',
        position: 'relative',
        top: '5px',
        width: '25px',
      },
    },
  },
];

let transformerRemarkPlugin = {
  resolve: `gatsby-transformer-remark`,
  options: {
    plugins: subRemarkPlugins
  },
};

module.exports = {
  siteMetadata: {
    title: config.siteTitle,
    siteUrl: config.siteUrl,
    description: config.siteDescription,
  },
  plugins: [
    {
      // keep as first gatsby-source-filesystem plugin for gatsby image support
      resolve: 'gatsby-source-filesystem',
      options: {
        path: `${__dirname}/static/img`,
        name: cmsUploadCMSName,
      },
    },
    gatsbyNetlifyCMSPaths,
    ...routes.routesArray.map((route) => {
      const contentPath = route.dir || route.path;
      return ({
        resolve: `gatsby-source-filesystem`,
        options: {
          name: contentPath,
          path: `${__dirname}/src/content/${contentPath}/`,
        },
      })
    }),
    {
      resolve: `gatsby-mdx`,
      options: {
        extensions: [".mdx", ".md"],
        gatsbyRemarkPlugins: subRemarkPlugins,
      }
    },
    `gatsby-plugin-postcss`,
    `gatsby-plugin-resolve-src`,
    `gatsby-plugin-catch-links`,
    `gatsby-transformer-sharp`,
    `gatsby-plugin-sharp`,
    transformerRemarkPlugin,
    {
      resolve: `gatsby-plugin-google-analytics`,
      options: {
        trackingId: process.env.GOOGLE_ANALYTICS_ID,
      },
    },
    `gatsby-plugin-emotion`,
    `gatsby-plugin-sitemap`,
    {
      resolve: "gatsby-plugin-netlify-cms",
      options: {
        modulePath: `${__dirname}/src/cms/cms.js`,
      },
    },
    {
      resolve: `gatsby-plugin-feed`,
      options: {
        query: `
          {
            site {
              siteMetadata {
                title
                description
                siteUrl
                site_url: siteUrl
              }
            }
          }
        `,
        feeds: [
          {
            serialize: ({ query: { site, allMdx } }) => {
              return allMdx.edges.map(edge => {
                return Object.assign({}, edge.node.frontmatter, {
                  description: edge.node.excerpt,
                  url: `${site.siteMetadata.siteUrl}/${edge.node.fields.source}${edge.node.fields.slug}`,
                  guid: `${site.siteMetadata.siteUrl}/${edge.node.fields.source}${edge.node.fields.slug}`,
                  custom_elements: [{ 'content:encoded': edge.node.html }],
                });
              });
            },
            query: `
              {
                allMdx(
                  limit: 1000,
                  sort: { order: DESC, fields: [fields___prefix] },
                  filter: { fields: { source: {eq: "posts"}, slug: { ne: null } } }
                ) {
                  edges {
                    node {
                      rawBody
                      code {
                        scope
                        body
                      }
                      tableOfContents
                      html
                      excerpt
                      fields {
                        slug
                        prefix
                        source
                      }
                      frontmatter {
                        title
                      }
                    }
                  }
                }
              }
            `,
            output: '/rss.xml',
          },
        ],
      },
    },
  ],
};
