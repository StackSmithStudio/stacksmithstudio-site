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

let introClassInternal = [%bs.raw {| css(tw`
  w-full
  mx-8
  lg:w-2/3
  lg:mx-0
  flex
  flex-wrap
  justify-center
  items-center
  `)
|}];

let logoBaseClass = [%bs.raw {| css(tw`
  text-white
  text-5xl
  pb-8
  w-full
  md:w-1/4
  md:pb-2
  text-center
  md:text-left
  flex
  `)
|}];
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
  justify-center
  w-full
  text-white
  text-4xl
  pt-8
  md:pt-0
  md:w-3/4
  md:pl-16
  text-center
  md:text-left
`)
|}];


let polishedTextClass = Utils.Transitions.polishTransitionStyle("all 3s ease 1s");
let polishedLogoClass = Utils.Transitions.polishTransitionStyle("all 3s ease .5s");

let textWrapperClass = cx(textWrapperBaseClass, polishedTextClass);
let logoClass = cx(logoBaseClass, polishedLogoClass);

let prevTextStyle = [%bs.raw {| css(tw` text-orange-light invisible `) |}];

let make = _children => {
  ...component,
  render: _self =>
    <div className=cx(introClass, "bg-steel")>
      <div className=introClassInternal>
        /* <WaypointGenerator wayKey="logo">
          ...{(~waypointEntered) => {
            <div className=cx(logoClass, Utils.Transitions.classTransitionInWithPrevClass(waypointEntered, prevTextStyle))>
              {ReasonReact.string("Logo Goes here")}
            </div>
          }}
        </WaypointGenerator> */
        <WaypointGenerator wayKey="maintext">
          ...{(~waypointEntered) => {
            <div className=cx(textWrapperClass, Utils.Transitions.classTransitionInWithPrevClass(waypointEntered, prevTextStyle))>
              {ReasonReact.string("StackSmithStudio")}
            </div>
          }}
        </WaypointGenerator>
      </div>
    </div>
};
