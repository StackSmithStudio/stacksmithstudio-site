let component = ReasonReact.statelessComponent("About");

let css = Css.css;
let tw = Css.tw;

let aboutClass = [%bs.raw {| css(tw`
  px-16
  lg:px-0
  text-lg
`)
|}];

let aboutTextWrapperClass = [%bs.raw {| css(tw`
  text-lg
  mb-16
  text-black
`)
|}];

let make = (~title, ~body, _children) => {
  ...component,
  render: _self =>
    <div className=aboutClass>
      <Section title=title>
        <div className=aboutTextWrapperClass>
          <Bodytext html_=body />
        </div>
      </Section>
    </div>,
};