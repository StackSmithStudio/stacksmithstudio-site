let component = ReasonReact.statelessComponent("Section");

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;

type orientation =
  | LEFT
  | CENTER;

type color =
  | STEEL
  | WHITE;

type size =
  | REGULAR
  | FULL;
let sectionClass = (color, size) =>
  cx(
    cx([%bs.raw {| css(tw`
      px-16
      lg:px-0
      bg-grey-lighter
      text-lg
      `)
    |}],
    switch(color){
    | STEEL => [%bs.raw {| css(tw` bg-grey-lighter `) |} ]
    | WHITE => "bg-steel"
    }
  ),
  switch(size){
  | REGULAR => ""
  | FULL => [%bs.raw {| css(tw` py-16 `) |} ]
  }
);

let orientationSwitch = (color) => {
  switch(color){
  | LEFT => [%bs.raw {| css(tw` flex justify-start`) |} ]
  | CENTER => [%bs.raw {| css(tw` flex justify-center`) |} ]
  }
};

let colorSwitch = (orientation) => {
  switch(orientation){
  | STEEL => [%bs.raw {| css(tw` text-grey-darker `) |} ]
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
      md:w-2/3
      lg:w-1/2
      xl:w-1/3
      `) |}
    ], colorSwitch(color)), orientationSwitch(orientation));

let titleWrapperClass = [%bs.raw
  {| css(tw`
  flex
  justify-center
  underline
  text-grey-darker
  mb-8
  `) |}
];

let contentWrapperClass = [%bs.raw
  {| css(tw`
  flex
  justify-center
  `) |}
];


let sectionContentClass = [%bs.raw
{| css(tw`
  w-full
  md:w-2/3
  lg:w-1/2
  xl:w-1/3
`) |}
];

let joinStringsWithSeparator = (listOfString : list(string), separator) =>
  listOfString
  |> Belt.List.reduce(_, "", (memo, splitString) => { memo ++ (memo == "" ? "" : separator) ++ splitString });

joinStringsWithSeparator(_, "-")
let make = (~title, ~orientation=LEFT, ~color=STEEL, ~size=REGULAR, children) => {
  ...component,
  render: _self =>
    <div className=sectionClass(color, size) id={title |> Utils.String.slugifyId}>
      <div className=titleWrapperClass>
        <div className=titleClass(orientation, color)> {ReasonReact.string(title)} </div>
      </div>
      <div className=contentWrapperClass>
        <div className=sectionContentClass>{children |> ReasonReact.array}</div>
      </div>
    </div>,
};