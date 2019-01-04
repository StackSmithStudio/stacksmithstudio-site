let component = ReasonReact.statelessComponent("Contact");

let css = Css.css;
let tw = Css.tw;

let contactClass = [%bs.raw {| css(tw`
  bg-grey-darkest
  text-grey-lighter
  pb-8
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
    <div className=contactClass>
      <Section title="Contact">
        <div key="contact-text" className=contactTextClass> {ReasonReact.string("Message me if you want to work with me!")} </div>
        <div key="contact-form" className=centerFormClass>
          <ContactForm />
        </div>
      </Section>
    </div>,
};