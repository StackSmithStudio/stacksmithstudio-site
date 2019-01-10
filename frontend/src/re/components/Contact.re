let component = ReasonReact.statelessComponent("Contact");

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;

let contactClass = [%bs.raw {| css(tw`
  text-white
`)
|}];

let contactTextClass = [%bs.raw {| css(tw`
  flex
  justify-center
  mb-4
  text-teal
`)
|}];

let centerFormClass = [%bs.raw {| css(tw`
  w-full
  flex
  justify-center
`)
|}];

let make = (~splashCss, ~mainCss, ~rowClass, _children) => {
  ...component,
  render: _self =>
    <Section orientation=Section.CENTER color=Section.STEEL size=Section.FULL title="Contact" splashCss mainCss rowClass>
      <div key="contact-form" className=centerFormClass>
        <ContactForm />
      </div>
    </Section>
};