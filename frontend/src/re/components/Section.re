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

let sectionClass = cx(
  [%bs.raw {| css(tw`
    flex
    flex-wrap
    relative
  `) |} ],
  Utils.Css.cssToEmotionMediaQuery(Utils.Css.SM, "
    display: contents;
  ")
);

let centerContent = [%bs.raw {| css(tw`
  flex
  items-center
`) |} ];

let splashClassInternal = [%bs.raw {| css(tw`
  sm:block
  absolute
  sm:static
  w-full
  h-full
  sm:w-auto
  sm:h-auto
`) |} ];

let textInternal = [%bs.raw {| css(tw`
  z-10
  px-4
  w-full
  sm:w-auto
`) |} ];

let imageInternal = [%bs.raw {| css(tw`
  z-10
  px-4
  w-full
  sm:w-auto
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
    <div className=sectionClass>
      <div className=cx(cx(splashClass, rowClass), splashClassInternal)/>
      /* <div className=cx(cx(titleWrapperClass, titleClass), rowClass)>
        <div className=cx(titleInternalClass, "rotate-270")> {ReasonReact.string(title)} </div>
      </div> */
      <div className=cx(cx(cx(centerContent, rowClass), textClass), textInternal)> {children |> ReasonReact.array} </div>
      {Belt.Option.mapWithDefault(image, <div />, (imageVal) =>
        <div className=cx(cx(cx(centerContent, rowClass), imageClass), imageInternal)>
          <img src=imageVal />
        </div>
      )}
    </div>
  }
};