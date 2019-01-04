let component = ReasonReact.statelessComponent("Part");

let css = Css.css;
let tw = Css.tw;

let make = (~title, ~body, ~orientation=Section.LEFT, ~color=Section.STEEL, _children) => {
  ...component,
  render: _self =>
    <About
      title
      body
      orientation
      color
    />
};