let component = ReasonReact.statelessComponent("About");

let css = Css.css;
let tw = Css.tw;

let aboutTextWrapperClass = [%bs.raw {| css(tw`
  text-lg
`)
|}];


let make = (~title, ~body, ~orientation=Section.LEFT, ~color=Section.STEEL, ~splashCss, ~mainCss, ~rowClass, _children) => {
  ...component,
  render: _self =>
    <>
      <Section title=title orientation color splashCss mainCss rowClass>
        <div className=aboutTextWrapperClass>
          <Bodytext html_=body className="markdownClass" />
        </div>
      </Section>
    </>,
};