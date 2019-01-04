let component = ReasonReact.statelessComponent("Contact");

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;

let contactClass = [%bs.raw {| css(tw`
  text-white
  py-16
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
  flex
  justify-center
`)
|}];

let make = _children => {
  ...component,
  render: _self =>
    <div className=cx(contactClass, "bg-steel")>
      <Section orientation=Section.CENTER color=Section.WHITE title="Contact">
        <div key="contact-form" className=centerFormClass>
          <ContactForm />
        </div>
      </Section>
    </div>,
};