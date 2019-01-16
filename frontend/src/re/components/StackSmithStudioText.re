let component = ReasonReact.statelessComponent("StackSmithStudioText");

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;

let logoText = [%bs.raw {| css(tw`
  flex
`) |}];

let logoWrapper = [%bs.raw {| css(tw`
  flex
`) |}];

let logoInternal = [%bs.raw {| css(tw`
  w-1/3
`) |}];

let make = (~text=true, ~logoClass="", ~dark=false, _children) => {
  ...component,
  render: _self => {
    switch(text){
    | true =>
      <div className=logoText>
        <div className="text-primary-cyan">
          {ReasonReact.string("Stack")}
        </div>
        <div className="text-primary-gold">
          {ReasonReact.string("Smith")}
        </div>
        <div className=(dark ? "text-primary-charcoal" : "text-primary-white")>
          {ReasonReact.string("Studio")}
        </div>
      </div>
    | false =>
      <div className=cx(logoClass, logoWrapper)>
        <div className=cx(logoInternal, "bg-primary-cyan") />
        <div className=cx(logoInternal, "bg-primary-gold") />
        <div className=cx(logoInternal, (dark ? "bg-primary-charcoal" : "bg-primary-white")) />
      </div>
    }
    
  }
};