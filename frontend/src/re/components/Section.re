let component = ReasonReact.statelessComponent("Section");

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;

/* let titleInternalClass = 
  [%bs.raw {| css(tw`
  pin-l
  w-24
  absolute
  text-xs
  `) |}
];

let titleWrapperClass = [%bs.raw {| css(tw`
  relative
  h-1
  mb-8
  italic
  `) |}
]; */

let centerContent = [%bs.raw {| css(tw`
  flex
  items-center
`) |} ];

let make = (
  ~title,
  ~textClass="",
  ~titleClass="",
  ~image=None,
  ~imageClass="",
  ~splashClass,
  ~rowClass,
children) => {
  ...component,
  render: _self => {
    Js.log("image - ");
    Js.log(image);
    <>
      <div className=cx(splashClass, rowClass)/>
      /* <div className=cx(cx(titleWrapperClass, titleClass), rowClass)>
        <div className=cx(titleInternalClass, "rotate-270")> {ReasonReact.string(title)} </div>
      </div> */
      
      {Belt.Option.mapWithDefault(image, <div />, (imageVal) =>
        <div className=cx(cx(centerContent, rowClass), imageClass)>
          <img src=imageVal />
        </div>
      )}
      <div className=cx(cx(centerContent, rowClass), textClass)> {children |> ReasonReact.array} </div>
    </>
  }
};