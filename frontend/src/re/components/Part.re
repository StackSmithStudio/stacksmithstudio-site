let component = ReasonReact.statelessComponent("Part");

let css = Css.css;
let tw = Css.tw;

let make = (~title, ~body, ~orientation=Section.LEFT, ~color=Section.STEEL, ~splashCss, ~mainCss, ~rowClass, _children) => {
  ...component,
  render: _self =>
    <About
      rowClass
      splashCss
      mainCss
      title
      body
      orientation
      color
    />
};