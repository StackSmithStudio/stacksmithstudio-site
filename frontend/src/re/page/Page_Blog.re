let component = ReasonReact.statelessComponent("Page_Blog");
[%bs.raw {|require('../../../../../src/styles/styles.css')|}];

/* TODO this needs to be fixed with proper links */
let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: _self =>
    <div>
      <Menu />
      <Article>
        <Blog
          items={
            props##data##posts##edges |> Belt.Array.map(_, edge => edge##node)
          }
          author="greg"
          metaIcons=PagePropType.metaIcons
        />
      </Article>
      <Footer
        links=props##data##footerLinks##html
        copyright=props##data##copyright##html
      />
      <Seo
        url=Config.config##siteUrl
        language=Config.config##siteLanguage
        title=Config.config##siteTitle
        description=Config.config##siteDescription
      />
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );