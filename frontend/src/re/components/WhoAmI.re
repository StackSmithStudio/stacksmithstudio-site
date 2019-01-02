let component = ReasonReact.statelessComponent("WhoAmI");

let css = Css.css;
let tw = Css.tw;

let imageSection = [%bs.raw
  {| css(tw`
  w-full
  sm:w-full
  md:w-1/2
  `)
  |}
];

let attributesSectionClass = [%bs.raw
  {| css(tw`
  w-full
  sm:w-full
  md:w-1/2

  flex
  flex-col
  justify-center
  `)
  |}
];

let whoAmIClass = [%bs.raw {| css(tw`
  w-full
  flex
  flex-wrap
`)
|}];

let make = _children => {
  ...component,
  render: _self =>
    <div className=whoAmIClass>
      <div className=imageSection> <Image /> </div>
      <div className=attributesSectionClass> <Attributes /> </div>
    </div>,
};