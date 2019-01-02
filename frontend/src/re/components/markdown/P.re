let component = ReasonReact.statelessComponent("P");
let css = Css.css;
let tw = Css.tw;

let pClass = [%bs.raw {| css(tw`
`)
|}];

let make = (children) => {
  ...component,
  render: _self =>
    <p className=pClass>
      {children |> ReasonReact.array}
    </p>,
};

let jsComponent =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));