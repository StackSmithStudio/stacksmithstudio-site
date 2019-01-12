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
  py-12
  w-full
`)
|}];

let splashClass = Utils.CssGrid.splashClass;

let make = (~rowClass, _children) => {
  ...component,
  render: _self =>
    <Section
      title="Contact"
      splashClass=cx(Part.colorToSplashClass(Part.STEEL), splashClass)
      textClass=Part.orientationToTextClass(Part.CENTER)
      rowClass
    >
      <div key="contact-form" className=centerFormClass>
        <ContactForm />
      </div>
    </Section>
};