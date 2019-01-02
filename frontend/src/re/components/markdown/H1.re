let component = ReasonReact.statelessComponent("H1");

let css = Css.css;
let tw = Css.tw;

let header1Class = [%bs.raw {| css(tw`
`)
|}];

let make = (children) => {
  ...component,
  render: _self =>
    <h1 className=header1Class>
      {children |> ReasonReact.array}
    </h1>,
};

let jsComponent =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));