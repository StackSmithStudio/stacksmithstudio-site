let component = ReasonReact.statelessComponent("About");

let css = Css.css;
let tw = Css.tw;

let aboutClass = [%bs.raw {| css(tw`
  px-16
`)
|}];

let make = _children => {
  ...component,
  render: _self =>
    <div className=aboutClass>
      <Section title="About">
        <Traits key="traits" />
        <WhoAmI key="whoami" />
      </Section>
    </div>,
};