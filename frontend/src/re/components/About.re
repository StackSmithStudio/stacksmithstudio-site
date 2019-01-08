let component = ReasonReact.statelessComponent("About");

let css = Css.css;
let tw = Css.tw;

let aboutClass = [%bs.raw {| css(tw`
`)
|}];

let aboutTextWrapperClass = [%bs.raw {| css(tw`
  text-lg
`)
|}];


let make = (~title, ~body, ~orientation=Section.LEFT, ~color=Section.STEEL, _children) => {
  ...component,
  render: _self =>
    <div className=aboutClass>
      <Section title=title orientation color>
        <div className=aboutTextWrapperClass>
          <Bodytext html_=body className="markdownClass" />
        </div>
      </Section>
    </div>,
};