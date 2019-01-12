let component = ReasonReact.statelessComponent("Template_Slides");

[%bs.raw {|require('../../../../../src/styles/styles.css')|}];
[%bs.raw {|require('prismjs/themes/prism-okaidia.css')|}];
[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];

let css = Css.css;
let tw = Css.tw;

/* TODO: NOTE the mdx renderer may have some problems transpiling */
/* let defaultComponents = MDXRenderer.defaultComponents; */

/* let spectacleSlidesClass = [%bs.raw {| css("") |}]; */

let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: _self => {
    let rawbodyWithImages =
      props##data##page##frontmatter##images
      |> Belt.List.fromArray
      |> Belt.List.reduce(_, props##data##page##rawBody, (memoBody, image) => {
        image##image##base
        |> Js.Re.fromStringWithFlags(_, "g")
        |> Js.String.replaceByRe(_, image##image##publicURL, memoBody);
      });
    /* images need to be in the images list */
    /* Note skips first page for metadata */
    /* TODO use mdx rendering when gatsby-mdx uses mdx-deck */
    <div>
      <SpectacleSlides markdown=rawbodyWithImages />
    </div>
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );