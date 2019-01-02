import { graphql } from 'gatsby';
import React from 'react';

import Page from '../../lib/es6_global/src/re/template/Template_Post.bs.js';

export default (props) => <Page props={props} />;

/* TODO MDX can't use named queries https://github.com/ChristopherBiscardi/gatsby-mdx/issues/202 */

export const pageQuery = graphql`
  query($slug: String!) {
    post: mdx(fields: { slug: { eq: $slug } }) {
      html
      rawBody
      code {
        scope
        body
      }
      tableOfContents
      fileAbsolutePath
      excerpt
      fields {
        slug
        prefix
      }
      frontmatter {
        title
        categories
      }
    }
    author: mdx(
      fileAbsolutePath: { regex: "/content/parts/author/" }
    ) {
      html
      rawBody
      code {
        scope
        body
      }
      tableOfContents
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
