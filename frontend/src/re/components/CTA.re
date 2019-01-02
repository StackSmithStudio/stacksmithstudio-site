let component = ReasonReact.statelessComponent("CTA");

let css = Css.css;
let tw = Css.tw;

type color =
  | DarkGrey
  | White;

let buttonClass(color) =
  switch(color){
  | DarkGrey =>
  [%bs.raw
    {| css(tw`
      bg-grey-darkest
      text-white
      border-solid
      text-xl
      py-2
      px-4
      hover:bg-teal
      hover:text-white
      border-2
      no-underline
      inline-flex
    `)
  |}
  ]
| White =>
  [%bs.raw
    {| css(tw`
        bg-white
        text-grey-darkest
        border-solid
        text-xl
        py-2
        px-4
        hover:bg-teal
        hover:text-white
        border-2
        no-underline
        inline-flex
      `)
    |}
  ]
};



let make = (~text, ~color=DarkGrey, _children) => {
  ...component,
  render: _self =>
      <div className=buttonClass(color)>
        {text |> ReasonReact.string}
      </div>
};
      