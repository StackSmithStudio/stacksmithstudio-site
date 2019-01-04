let component = ReasonReact.statelessComponent("Section");

let css = Css.css;
let tw = Css.tw;

let sectionClass = [%bs.raw {| css(tw`
  pt-16
  `) |}];

let titleClass = [%bs.raw
  {| css(tw`
  text-5xl
  font-bold
  
  w-full
  md:w-3/4
  lg:w-1/2
  `) |}
];

let titleWrapperClass = [%bs.raw
  {| css(tw`
  flex
  justify-center
  underline
  text-blue
  mb-8
  `) |}
];

let contentWrapperClass = [%bs.raw
  {| css(tw`
  flex
  justify-center
  mb-8
  `) |}
];


let sectionContentClass = [%bs.raw
{| css(tw`
  w-full
  md:w-3/4
  lg:w-1/2
`) |}
];

let make = (~title, children) => {
  ...component,
  render: _self =>
    <div className=sectionClass id={String.lowercase(title)}>
      <div className=titleWrapperClass>
        <div className=titleClass> {ReasonReact.string(title)} </div>
      </div>
      <div className=contentWrapperClass>
        <div className=sectionContentClass>{children |> ReasonReact.array}</div>
      </div>
    </div>,
};