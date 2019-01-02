import { graphql } from 'gatsby';
import React from 'react';

import Page from '../../lib/es6_global/src/re/template/Template_Category.bs.js';

export default (props) => <Page props={props} />;

/* TODO MDX can't use named queries https://github.com/ChristopherBiscardi/gatsby-mdx/issues/202 */

export const pageQuery = graphql`
  query ($category: String!) {
    posts: allMdx(
      limit: 1000
      sort: { fields: [fields___prefix], order: DESC }
      filter: { frontmatter: { categories: { eq: $category } } }
    ) {
      totalCount
      edges {
        node {
          fields {
            slug
          }
          code {
            scope
            body
          }
          tableOfContents
          rawBody
          excerpt
          timeToRead
          frontmatter {
            title
            categories
          }
        }
      }
    }
    footerLinks: mdx(
      fileAbsolutePath: { regex: "/content/parts/footerLinks/" }
    ) {
      html
      code {
        scope
        body
      }
      tableOfContents
      rawBody
    }
    copyright: mdx(
      fileAbsolutePath: { regex: "/content/parts/copyright/" }
    ) {
      html
      code {
        scope
        body
      }
      tableOfContents
      rawBody
    }
  }
`;