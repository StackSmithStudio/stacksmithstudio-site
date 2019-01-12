let component = ReasonReact.statelessComponent("SouthSmithStudioText");

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;

let make = (_children) => {
  ...component,
  render: _self => {
    <>
      <div className="text-primary-cyan">
        {ReasonReact.string("Stack")}
      </div>
      <div className="text-primary-gold">
        {ReasonReact.string("Smith")}
      </div>
      <div className="text-primary-white">
        {ReasonReact.string("Studio")}
      </div>
    </>
  }
};