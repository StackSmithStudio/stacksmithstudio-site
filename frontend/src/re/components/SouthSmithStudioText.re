let component = ReasonReact.statelessComponent("SouthSmithStudioText");

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;

let make = (_children) => {
  ...component,
  render: _self => {
    <>
      <div className="text-cyan">
        {ReasonReact.string("Stack")}
      </div>
      <div className="text-gold">
        {ReasonReact.string("Smith")}
      </div>
      <div className="text-white">
        {ReasonReact.string("Studio")}
      </div>
    </>
  }
};