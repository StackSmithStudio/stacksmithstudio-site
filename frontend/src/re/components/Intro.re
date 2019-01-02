let component = ReasonReact.statelessComponent("Intro");

let css = Css.css;
let tw = Css.tw;
let introClass = [%bs.raw
  {| css(tw`
    flex
    justify-center
    items-center
    w-full
    h-full
    bg-grey-darkest
  `) |}
];

let textClass = [%bs.raw {| css(tw`
  text-white
  text-5xl
  pb-2
  `)
|}];

let buttonClass = [%bs.raw
  {| css(tw`
    no-underline
  `)
|}
];

let buttonWrapperClass = [%bs.raw {| css(tw`
  flex
  justify-center
`)
|}];

let make = _children => {
  ...component,
  render: _self =>
    <div className=introClass>
      <div>
        <div className=textClass> {ReasonReact.string("The Most Greg")} </div>
        <div className=buttonWrapperClass>
          <a href="#projects" className=buttonClass>
            <CTA text="View my work" />
          </a>
        </div>
      </div>
    </div>,
};