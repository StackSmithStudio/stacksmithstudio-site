import React from 'react';
import { graphql } from 'gatsby';

import Page from '../../lib/es6_global/src/re/page/Page_Resume.bs.js';

let isBrowser = typeof window !== 'undefined';

let renderPage = (props) => <Page props={props} />;

export default (props) => isBrowser ? renderPage(props) : <div />;

export const query = graphql`
  query {
    projects: allMdx(
      filter: {
        frontmatter: {
          resume: {eq: true}
        },
        fields: {
          source: {eq: "projects"},
          slug: {ne: null}
        }
      }
      sort: { order: DESC, fields: [frontmatter___endDate] }
    ) {
      edges {
        node {
          id
          html
          rawBody
          excerpt(pruneLength: 100000)
          fields {
            slug
            prefix
          }
          frontmatter {
            jobType
            role
            startTime
            endTime
            endDate
            title
            categories
            cover{
              publicURL
            }
            images{
              image {
                publicURL
              }
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
