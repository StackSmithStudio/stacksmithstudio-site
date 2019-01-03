let component = ReasonReact.statelessComponent("About");

let css = Css.css;
let tw = Css.tw;

let aboutClass = [%bs.raw {| css(tw`
  px-16
  text-lg
`)
|}];

let aboutTextClass = [%bs.raw {| css(tw`
  w-full
  lg:w-2/3
  xl:w-1/3
`)
|}];

let aboutTextWrapperClass = [%bs.raw {| css(tw`
  flex
  justify-center
  text-lg
  mb-16
  text-black
`)
|}];

let make = _children => {
  ...component,
  render: _self =>
    <div className=aboutClass>
      <Section title="We learn your business alongside you.">
        <div className=aboutTextWrapperClass>
            {ReasonReact.string("StackSmithStudio cutting edge consulting company working in Brookyn, New York.")}
        </div>
        <div className=aboutTextWrapperClass>
            {ReasonReact.string("StackSmithStudio helps supports companies optimize business process and getting their brand recognized. Our design and tech are always forward facing. We understand how to work with clients. We companies fully flesh out and conceptialize their domain so they may achieve their vision.")}
        </div>
        </Section>
    </div>,
};