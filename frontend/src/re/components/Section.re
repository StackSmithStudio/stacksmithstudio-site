let component = ReasonReact.statelessComponent("Section");

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;

type orientation =
  | LEFT
  | CENTER;

type color =
  | BLUE
  | WHITE;
let sectionClass = [%bs.raw {| css(tw`
  pt-16
  px-16
  lg:px-0
  text-lg
  `) |}];

let orientationSwitch = (color) => {
  switch(color){
  | LEFT => [%bs.raw {| css(tw` flex justify-start`) |} ]
  | CENTER => [%bs.raw {| css(tw` flex justify-center`) |} ]
  }
};

let colorSwitch = (orientation) => {
  switch(orientation){
  | BLUE => [%bs.raw {| css(tw` text-blue `) |} ]
  | WHITE => [%bs.raw {| css(tw` text-white no-underline `) |} ]
  }
};



let titleClass = (orientation: orientation, color: color) => 
  cx(cx(
    [%bs.raw
      {| css(tw`
      text-5xl
      font-bold
      
      w-full
      md:w-3/4
      lg:w-1/2
      `) |}
    ], colorSwitch(color)), orientationSwitch(orientation));

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



let make = (~title, ~orientation=LEFT, ~color=BLUE, children) => {
  ...component,
  render: _self =>
    <div className=sectionClass id={String.lowercase(title)}>
      <div className=titleWrapperClass>
        <div className=titleClass(orientation, color)> {ReasonReact.string(title)} </div>
      </div>
      <div className=contentWrapperClass>
        <div className=sectionContentClass>{children |> ReasonReact.array}</div>
      </div>
    </div>,
};