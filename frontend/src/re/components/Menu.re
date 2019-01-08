let component = ReasonReact.statelessComponent("Menu");

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;

let menuClass = [%bs.raw
  {| css(tw`
    flex
    w-full
    h-full
    py-6
    justify-center
  `) |}
];

let menuInternalClass = [%bs.raw
  {| css(tw`
    flex
    justify-between
  `) |}
];

let polishedClass = Utils.Transitions.polishTransitionStyle("all .5s ease 0s");

let baseLinkClass = [%bs.raw
  {| css(tw`
  mx-6
  normal-case
  text-white
  no-underline
  hover:text-white

  border-0
  border-b-4
  border-transparent
  border-solid

  hover:border-white
`) |}
];

let linkClass = cx(baseLinkClass, polishedClass);


let make = (~parts, _children) => {
  ...component,
  render: _self => {
    let parts = Belt.List.fromArray(parts);

    let home = Config.menu |> Belt.List.fromArray |> Belt.List.getBy(_, (menuItem) => menuItem##label == "Home");
    let contact = Config.menu |> Belt.List.fromArray |> Belt.List.getBy(_, (menuItem) => menuItem##label == "Contact");

    <div className=menuClass>
      <div className=menuInternalClass>
        {
          Belt.Option.mapWithDefault(home, <div />, menuItem => {
            <a
              className=linkClass
              key={Type.Config.to_(menuItem)}
              href={Type.Config.to_(menuItem)}>
              {ReasonReact.string(menuItem##label)}
            </a>
          })
        }
        /* <>
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
        </> */
        {
          Belt.Option.mapWithDefault(contact, <div />, menuItem => {
            <a
              className=linkClass
              key={Type.Config.to_(menuItem)}
              href={Type.Config.to_(menuItem)}>
              {ReasonReact.string(menuItem##label)}
            </a>
          })
        }
      </div>
    </div>
  }
};