let component = ReasonReact.statelessComponent("Template_Category");

[%bs.raw {|require('../../../../../src/styles/styles.css')|}];
[%bs.raw {|require('prismjs/themes/prism-okaidia.css')|}];
[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];

let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: _self => {
    Js.log("Page_Category props = ");
    Js.log(props);
    <div>
      /* <Menu /> */
      <Article>
        <Heading>
          <span> {ReasonReact.string("Posts in category")} </span>
          <TagIcon />
          <h1> {ReasonReact.string(props##pageContext##category)} </h1>
          <p className="meta">
            {
              ReasonReact.string(
                "There "
                ++ (props##data##posts##totalCount > 1 ? "are " : "is "),
              )
            }
            <strong>
              {
                props##data##posts##totalCount
                |> string_of_int
                |> ReasonReact.string
              }
            </strong>
            {ReasonReact.string(" ")}
            {
              ReasonReact.string(
                "post" ++ (props##data##posts##totalCount > 1 ? "s" : ""),
              )
            }
            {ReasonReact.string(" in the category")}
          </p>
        </Heading>
        <List
          items={
            props##data##posts##edges |> Belt.Array.map(_, edge => edge##node)
          }
        />
      </Article>
      /* <Footer
        links=props##data##footerLinks##html
        copyright=props##data##copyright##html
      /> */
      <Seo
        url={
          Config.config##siteUrl
          ++ "/categories/"
          ++
          props##pageContext##category
          ++ "/"
        }
        language=Config.config##siteLanguage
        title={
          "Posts in category: "
          ++
          props##pageContext##category
          ++
          Config.config##siteTitlePostfix
        }
        description=Config.config##siteDescription
      />
    </div>
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );