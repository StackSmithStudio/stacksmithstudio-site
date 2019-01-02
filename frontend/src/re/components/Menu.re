let component = ReasonReact.statelessComponent("Menu");

let css = Css.css;
let tw = Css.tw;

let menuClass = [%bs.raw
  {| css(tw`
    w-full
    h-full
    
    bg-black
    border-0
    border-b-4
    border-teal
    border-solid

    py-4
    flex
    justify-between

    md:block

    
  `) |}
];

let linkClass = [%bs.raw
  {| css(tw`
  px-6
  normal-case
  text-white
  no-underline
`) |}
];

let make = _children => {
  ...component,
  render: _self =>
      <div className=menuClass>
        {
          Config.menu
          |> Belt.Array.map(_, menuItem =>
               <a
                 className=linkClass
                 key={Type.Config.to_(menuItem)}
                 href={Type.Config.to_(menuItem)}>
                 {ReasonReact.string(menuItem##label)}
               </a>
             )
          |> ReasonReact.array
        }
      </div>
};