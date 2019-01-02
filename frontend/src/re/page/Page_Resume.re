[%bs.raw {|require('../../../../../src/styles/styles.css')|}];
[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];
[%bs.raw {|require('tailwindcss/tailwind.css')|}];

let css = Css.css;
let tw = Css.tw;

let viwerClassName = [%bs.raw
  {| css(tw`
    w-screen
    h-screen
  `) |}
];

let component = ReasonReact.statelessComponent("Page_Resume");

let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: self => {
    <ReactPdfViewer className=viwerClassName>
      <Resume props/>
    </ReactPdfViewer>
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );