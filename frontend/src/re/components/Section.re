let component = ReasonReact.statelessComponent("Section");

let css = Css.css;
let tw = Css.tw;

let sectionClass = [%bs.raw {| css(tw`
  pt-16
  `) |}];

let titleClass = [%bs.raw
  {| css(tw`
  text-3xl
  w-full
  flex
  justify-center
  underline
  mb-8
  `) |}
];

let make = (~title, children) => {
  ...component,
  render: _self =>
    <div className=sectionClass id={String.lowercase(title)}>
      <div className=titleClass> {ReasonReact.string(title)} </div>
      {children |> ReasonReact.array}
    </div>,
};