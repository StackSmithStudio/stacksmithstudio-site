let component = ReasonReact.statelessComponent("SouthSmithStudioText");

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;

let logoText = [%bs.raw {| css(tw`
  flex
  text-2xl
`) |}];


let make = (_children) => {
  ...component,
  render: _self => {
    <div className=logoText>
      <div className="text-primary-cyan">
        {ReasonReact.string("Stack")}
      </div>
      <div className="text-primary-gold">
        {ReasonReact.string("Smith")}
      </div>
      <div className="text-primary-white">
        {ReasonReact.string("Studio")}
      </div>
    </div>
  }
};