let component = ReasonReact.statelessComponent("Traits");

let css = Css.css;
let tw = Css.tw;

type traits = list(Trait.trait);
let traits: traits = [
  {
    label: "Driven",
    copy: "Goes beyond what is requested.",
    icon: Edit2Icon.comp,
  },
  {
    label: "Passionate",
    copy: "Cares deeply about technology.",
    icon: ZapIcon.comp,
  },
  {
    label: "Connected",
    copy: "Always on the clients team.",
    icon: GlobeIcon.comp,
  },
  {
    label: "Empathetic",
    copy: "Puts self into users shoes always.",
    icon: UsersIcon.comp,
  },
];

let traitClass = [%bs.raw
  {| css(tw`
  w-full
  sm:w-full
  md:w-1/2
  lg:w-1/4
`)
|}
];

let traitsClass = [%bs.raw
  {| css(tw`
  w-full
  flex
  flex-wrap
  justify-center
  pb-12
`)
|}
];

let make = _children => {
  ...component,
  render: _self =>
    <div className=traitsClass>
      {
        traits
        |> Belt.List.map(_, (trait: Trait.trait) =>
             <div key={trait.label} className=traitClass>
               <Trait trait />
             </div>
           )
        |> Utils.ReasonReact.listToReactArray
      }
    </div>,
};