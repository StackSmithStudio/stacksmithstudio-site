let component = ReasonReact.statelessComponent("Attribute");

let css = Css.css;
let tw = Css.tw;

type attribute = {
  label: string,
  percentage: float,
};

let attributeClass = [%bs.raw {| css(tw`
  flex
  text-white
  relative
`)
|}];

let labelClass = [%bs.raw {| css(tw`
  w-1/3
  h-6
  bg-teal
  flex
  justify-center
  items-center
  `)
  |}];

let percentageClass = [%bs.raw {| css(tw`
  w-2/3
  h-6
  flex
  `)
  |}];

let colorBarPercentageClass = [%bs.raw {| css(tw`
  bg-teal-dark
  `)
  |}];

let remainingPercentageClass = [%bs.raw {| css(tw`
  bg-grey-light
  `)
  |}];

let labelTextClass = [%bs.raw {| css(tw`
  text-xs
  lg:text-sm
  `)
  |}];

let remainingPercentageText = [%bs.raw
  {| css(tw`
  text-grey-darkest
  float-right
  h-full
  text-xs
  lg:text-sm
  `)
  |}
];

let alignPercentageText = [%bs.raw
{| css(tw`
  h-full
  w-full
  absolute
  flex
  justify-end
  text-black
  items-center
  pr-2
`)
|}
];

let colorBarPercentageStyle = percentage =>
  ReactDOMRe.Style.make(
    ~width=string_of_int(percentage |> int_of_float) ++ "%",
    (),
  );

let remainingPercentageStyle = percentage =>
  ReactDOMRe.Style.make(
    ~width=string_of_int(100.0 -. percentage |> int_of_float) ++ "%",
    (),
  );

let make = (~attribute, _children) => {
  ...component,
  render: _self =>
    <div className=attributeClass>
      <div className=labelClass>
        <div className=labelTextClass>
          {ReasonReact.string(attribute.label)}
        </div>
      </div>
      <div className=percentageClass>
        <div
          style={colorBarPercentageStyle(attribute.percentage)}
          className=colorBarPercentageClass
        />
        <div
          style={remainingPercentageStyle(attribute.percentage)}
          className=remainingPercentageClass>
          <div className=remainingPercentageText>
          </div>
        </div>
      </div>
      <div className=alignPercentageText>
        {
          ReasonReact.string(
            (attribute.percentage |> string_of_float) ++ "%",
          )
        }
        </div>
    </div>,
};