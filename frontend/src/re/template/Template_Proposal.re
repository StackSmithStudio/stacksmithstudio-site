let component = ReasonReact.statelessComponent("Template_Proposal");

[%bs.raw {|require('../../../../../src/styles/styles.css')|}];
[%bs.raw {|require('prismjs/themes/prism-okaidia.css')|}];
[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];

let css = Css.css;
let tw = Css.tw;

/* let defaultComponents = MDXRenderer.defaultComponents; */
let layoutClass = [%bs.raw {| css(tw`my-0 text-xl leading-tight bg-blue`) |}];

let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: _self => {
    <div>
      <Article>
        <Bodytext html_=props##data##page##html />
      </Article>
    </div>

    /* Clean up the MDX a bit later */
    /* <div>
      <Article>
        <Heading title=props##data##page##frontmatter##title />
        <MDXRenderer
          components=({
            ...defaultComponents,
            h1: Some(H1.jsComponent),
            h2: Some(H2.jsComponent),
            h3: Some(H3.jsComponent),
            p: Some(P.jsComponent),
          })
        >
          {props##data##page##code##body}
        </MDXRenderer>
      </Article>
      <div>
      </div>
    </div> */
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );