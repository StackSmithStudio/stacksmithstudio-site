import { graphql } from 'gatsby';
import React from 'react';

import Page from '../../lib/es6_global/src/re/template/Template_Proposal.bs.js';

export default (props) => <Page props={props} />;

/* TODO MDX can't use named queries https://github.com/ChristopherBiscardi/gatsby-mdx/issues/202 */

export const pageQuery = graphql`
  query($slug: String!) {
    page: mdx(fields: { slug: { eq: $slug } }) {
      html
      rawBody
      code {
        scope
        body
      }
      tableOfContents
      excerpt
      fileAbsolutePath
      fields {
        slug
        prefix
      }
      frontmatter {
        title
        categories
        images{
          base
          publicURL
        }
      }
    }
    footerLinks: mdx(
      fileAbsolutePath: { regex: "/content/parts/footerLinks/" }
    ) {
      html
      rawBody
      code {
        scope
        body
      }
      tableOfContents
    }
    copyright: mdx(
      fileAbsolutePath: { regex: "/content/parts/copyright/" }
    ) {
      html
      rawBody
      code {
        scope
        body
      }
      tableOfContents
    }
  }
`;
