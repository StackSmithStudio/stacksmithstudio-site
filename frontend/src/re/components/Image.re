let component = ReasonReact.statelessComponent("Image");

let css = Css.css;
let tw = Css.tw;

let imageClass = [%bs.raw {| css(tw`
  w-full
  flex
  justify-center
  mb-8
`)
|}];

let jpgClass = [%bs.raw
  {| css(tw`
  bg-no-repeat
  w-full
  h-full
  rounded-full
  bg-contain
  `)
  |}
];

let buttonClass = [%bs.raw
  {| css(tw`
    no-underline
    flex
    justify-center
  `)
  |}
];

let make = _children => {
  ...component,
  render: _self =>
    <div className=imageClass>
      <div>
        <CircleInfo
          size=LG
          label="Who is Greg?"
          copy=Helper_Me.about
          comp={<div className={jpgClass ++ " bg-steel"} />}
        />
        <a href="#contact" className=buttonClass >
          <CTA text="Contact Me" color=White />
        </a>
      </div>
    </div>,
};