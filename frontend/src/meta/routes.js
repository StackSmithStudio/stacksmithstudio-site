const path = require('path');

const postTemplate = path.resolve('./src/templates/PostTemplate.js');
const pageTemplate = path.resolve('./src/templates/PageTemplate.js');
const proposalTemplate = path.resolve('./src/templates/ProposalTemplate.js');
const slidesTemplate = path.resolve('./src/templates/SlidesTemplate.js');

const routesArray = [
  {
    path: "parts"
  },
  {
    path: "posts",
    template: postTemplate,
    context: (edge, index, edges) => {
      const slug = edge.node.fields.slug;
      const next = index === 0 ? undefined : edges[index - 1].node;
      const prev =
        index === edges.length - 1 ? undefined : edges[index + 1].node;
      return {
        slug,
        prev,
        next
      };
    }
  },
  {
    path: "pages",
    template: pageTemplate,
    context: (edge) => {
      const slug = edge.node.fields.slug;
      const source = edge.node.fields.source;
      return {
        slug,
        source,
      };
    },
  },
  {
    path: "parts",
    template: pageTemplate, /* shouldn't have a page */
    context: (edge) => {
      const slug = edge.node.fields.slug;
      const source = edge.node.fields.source;
      return {
        slug,
        source,
      };
    },
  },
  {path: "projects"},
  {
    dir: "proposals",
    path: "slides",
    template: slidesTemplate,
    context: (edge) => {
      const slug = edge.node.fields.slug;
      const source = edge.node.fields.source;
      return {
        slug,
        source,
      };
    },
  },
  {
    dir: "proposals",
    path: "proposals",
    template: proposalTemplate,
    context: (edge) => {
      const slug = edge.node.fields.slug;
      const source = edge.node.fields.source;
      return {
        slug,
        source,
      };
    },
  },
];

module.exports = { routesArray };