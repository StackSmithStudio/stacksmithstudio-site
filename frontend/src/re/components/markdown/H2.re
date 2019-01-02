let component = ReasonReact.statelessComponent("H2");

let css = Css.css;
let tw = Css.tw;

let h2Class = [%bs.raw {| css(tw`
`)
|}];

let make = (children) => {
  ...component,
  render: _self =>
    <h2 className=h2Class>
      {children |> ReasonReact.array}
    </h2>,
};

let jsComponent =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));