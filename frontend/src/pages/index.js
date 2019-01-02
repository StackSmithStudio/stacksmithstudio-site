import React from 'react';
import { graphql } from 'gatsby';

import Index from '../../lib/es6_global/src/re/page/Page_Index.bs.js';

export default (props) => <Index props={props} />;

export const query = graphql`
  query {
    projects: allMdx(filter: {frontmatter: {featured:{eq: true}}, fields: {source: {eq: "projects"}, slug: {ne: null}}}) {
      edges {
        node {
          id
          html
          excerpt(pruneLength: 250)
          fields {
            slug
            prefix
          }
          frontmatter {
            title
            categories
            cover{
              publicURL
            }
            images{
              publicURL
            }
          }
        }
      }
    }
    footerLinks: mdx(
      fileAbsolutePath: { regex: "/content/parts/footerLinks/" }
    ) {
      html
    }
    copyright: mdx(
      fileAbsolutePath: { regex: "/content/parts/copyright/" }
    ) {
      html
    }
  }
`;
