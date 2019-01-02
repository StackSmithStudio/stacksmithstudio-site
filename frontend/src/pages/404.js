import React from 'react';
import { graphql } from 'gatsby';

import Page404 from '../../lib/es6_global/src/re/page/Page_404.bs.js';

export default (props) => <Page404 props={props} />;

export const query = graphql`
  query {
    notFound: mdx(
      fileAbsolutePath: { regex: "/content/parts/notFound/" }
    ) {
      html
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
