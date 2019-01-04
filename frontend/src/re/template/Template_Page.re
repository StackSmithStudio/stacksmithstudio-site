let component = ReasonReact.statelessComponent("Template_Page");

[%bs.raw {|require('../../../../../src/styles/styles.css')|}];
[%bs.raw {|require('prismjs/themes/prism-okaidia.css')|}];
[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];

let css = Css.css;
let tw = Css.tw;

let layoutClass = [%bs.raw {| css(tw`my-0 text-xl leading-tight bg-blue`) |}];
let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: _self => {
    <div>
      <Article>
        <Heading title=props##data##page##frontmatter##title />
        <Bodytext html_=props##data##page##html />
      </Article>
      /* <Footer
        links=props##data##footerLinks##html
        copyright=props##data##copyright##html
      /> */
      <Seo
        url={Config.config##siteUrl ++ props##data##page##fields##slug}
        language=Config.config##siteLanguage
        title={
          props##data##page##frontmatter##title
          ++
          Config.config##siteTitlePostfix
        }
        description=props##data##page##excerpt
      />
    </div>
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );