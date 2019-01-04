let component = ReasonReact.statelessComponent("ContactForm");

let css = Css.css;
let tw = Css.tw;

let emailClass = [%bs.raw
  {| css(tw`
  flex
  w-full
  bg-black
  text-white
  p-2
  mb-4
`)
|}
];

let messageClass = [%bs.raw
  {| css(tw`
  flex
  w-full
  mb-4
  bg-black
  text-white
  p-2
  h-48
`)
|}
];


let formClass = [%bs.raw {| css(tw`
  w-full
`)
|}];

let make = _children => {
  ...component,
  render: _self =>
    <form
      method="POST"
      action="https://formspree.io/gregt87@gmail.com"
      className=formClass>
      <input
        type_="email"
        name="email"
        placeholder="Your email"
        className=emailClass
      />
      <textarea
        name="message"
        placeholder="Your message"
        className=messageClass
      />
      
      <button type_="submit">
        <CTA text="Send" />
      </button>
    </form>,
};