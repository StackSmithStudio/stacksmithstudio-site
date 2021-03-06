let component = ReasonReact.statelessComponent("Intro");

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;
let introClass = [%bs.raw
  {| css(tw`
    flex
    flex-wrap
    justify-center
    items-center
    w-full
    h-full
    pb-16
  `) |}
];

let textClass = [%bs.raw {| css(tw`
  `)
|}];

let anvilInternalClass = [%bs.raw {| css(tw`
  bg-contain
  bg-no-repeat
  bg-right-bottom
`) |}];

/* 
let introSeparatorClass = [%bs.raw {| css(tw`
  border-0
  border-white
  border-b-2
  border-r-0
  md:border-r-2
  md:border-b-0
  md:pb-2
  border-solid
  h-full
`)|}]; */

let buttonClass = [%bs.raw
  {| css(tw`
    no-underline
  `)
|}
];

let textWrapperBaseClass = [%bs.raw {| css(tw`
  flex
  w-full
  text-white
  text-2xl
  pt-8
`)
|}];


let polishedTextClass = Utils.Transitions.polishTransitionStyle("all 3s ease 1s");
let polishedLogoClass = Utils.Transitions.polishTransitionStyle("all 3s ease .5s");

let textWrapperClass = cx(textWrapperBaseClass, polishedTextClass);

let prevTextStyle = [%bs.raw {| css(tw`
  text-orange-light
  invisible
`) |}];

let logoClass = [%bs.raw {| css(tw`
  h-8
  w-8
`) |}];

let make = (~splashClass, ~rowClass, ~mainClass, ~anvilClass, _children) => {
  ...component,
  render: _self =>
    <>
      <div className=cx(cx(cx(introClass, rowClass), "bg-primary-charcoal"), splashClass)/>
      <div className=cx(anvilInternalClass, cx(rowClass, cx(anvilClass, "bg-anvil")))/>
      <div className=cx(cx(rowClass, textClass), mainClass)>
        /* <WaypointGenerator wayKey="maintext">
          ...{(~waypointEntered) => {
            <div className=cx(textWrapperClass, Utils.Transitions.classTransitionInWithPrevClass(waypointEntered, prevTextStyle))>
              <StackSmithStudioText />
            </div>
          }}
        </WaypointGenerator> */
        <div className=textWrapperClass>
          <StackSmithStudioText />
        </div>
        /* <StackSmithStudioText text=false logoClass /> */
      </div>
      /* <div className=cx(rowClass, cx("bg-anvil", anvilClass)) /> */
    </>
};
