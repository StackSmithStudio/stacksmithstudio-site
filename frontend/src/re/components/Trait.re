let component = ReasonReact.statelessComponent("Trait");

let css = Css.css;
let tw = Css.tw;

type trait = {
  label: string,
  copy: string,
  icon: ReasonReact.reactClass,
};

let iconClass = [%bs.raw {| css(tw`
  text-white
`)
|}];

let make = (~trait: trait, _children) => {
  ...component,
  render: _self =>
    <CircleInfo
      label={trait.label}
      copy={trait.copy}
      comp={<Icon comp={trait.icon} className=iconClass />}
    />,
};