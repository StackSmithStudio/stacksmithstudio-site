let component = ReasonReact.statelessComponent("Section");

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;

type orientation =
  | LEFT
  | RIGHT
  | CENTER;

type color =
  | STEEL
  | GREY
  | WHITE;

let colors = [WHITE, STEEL, GREY];
let orientations = [LEFT, CENTER, RIGHT];

type size =
  | REGULAR
  | FULL;

let colorSwitch = (orientation) => {
  switch(orientation){
  | STEEL => cx([%bs.raw {| css(tw`  text-white `) |} ], "bg-steel")
  | GREY => [%bs.raw {| css(tw` text-grey-darker bg-grey-light `) |} ]
  | WHITE => [%bs.raw {| css(tw` text-grey-darker bg-grey-lighter `) |} ]
  }
};

let sectionWrapper = (color, size) =>
  cx(
    cx(
      [%bs.raw {| css(tw`
        lg:px-0
        pt-32
        bg-grey-lighter
        `)
      |}],
    switch(size){
    | REGULAR => ""
    | FULL => [%bs.raw {| css(tw` py-16 `) |} ]
    }
  ),
  colorSwitch(color)
);

let sectionFlex = 
  [%bs.raw {| css(tw`
    flex
    mx-5
    `)
  |}]
;

let sectionClass = (orientation) =>
  switch(orientation){
  | _ =>  [%bs.raw {| css(tw`  mt-12`)|}]
  };

let sectionGutter = [%bs.raw {| css(tw` w-1/12 `)|}];

let sectionGutterLeft = (orientation) =>
  switch(orientation){
  | RIGHT =>  sectionGutter
  | _ => sectionGutter
  };

let sectionGutterRight = (orientation) =>
  switch(orientation){
  | LEFT => sectionGutter
  | _ => [%bs.raw {| css(tw` hidden `)|}]
  };
  

let titleClass = 
  [%bs.raw
    {| css(tw`
    pin-l
    w-24
    absolute
    text-xs
    `) |}
  ];

let titleWrapperClass = [%bs.raw
  {| css(tw`
  relative
  h-1
  mb-8
  italic
  `) |}
];

let contentWrapperClass = [%bs.raw
  {| css(tw`
  flex
  flex-wrap
  justify-center
  `) |}
];


let sectionContentClass = [%bs.raw
{| css(tw`
  w-full
  md:w-2/3
`) |}
];

let joinStringsWithSeparator = (listOfString : list(string), separator) =>
  listOfString
  |> Belt.List.reduce(_, "", (memo, splitString) => { memo ++ (memo == "" ? "" : separator) ++ splitString });

joinStringsWithSeparator(_, "-")
let make = (~title, ~orientation=CENTER, ~color=STEEL, ~size=REGULAR, ~image="", ~splashCss, ~mainCss, ~rowClass, children) => {
  ...component,
  render: _self =>
    <>
      <div className=cx(cx(sectionWrapper(color, size), splashCss), rowClass)/>
      /* <div className=sectionFlex>
        <div className=titleWrapperClass>
          <div className=cx(titleClass, "rotate-270")> {ReasonReact.string(title)} </div>
        </div>
      </div> */
      <div className=cx(mainCss, rowClass)>
        <div className=sectionClass(orientation) id={title |> Utils.String.slugifyId}>
          <div className=cx(contentWrapperClass, "main")>
            {
              switch(orientation) {
              | LEFT => <img src=image/>
              | _ => <div/>
              }
            }
            <div className=sectionContentClass>{children |> ReasonReact.array}</div>
            {
              switch(orientation) {
              | RIGHT => <img src=image/>
              | _ => <div/>
              }
            }
          </div>
        </div>
        /* <div className=sectionGutterRight(orientation) /> */
      </div>
    </>
};