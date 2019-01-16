let component = ReasonReact.statelessComponent("Part");

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;


type color =
  | STEEL
  | GREY
  | WHITE;

type orientation =
  | LEFT
  | RIGHT
  | CENTER;

let colors = [GREY, WHITE];

let orientations = [LEFT, RIGHT, CENTER];


/* this is coupled with Page Index Grid */
let splashClass = Utils.CssGrid.splashClass;

let colorTextSwitch = (color) => {
  switch(color){
  | STEEL => "text-white"
  | GREY => "text-primary-charcoal"
  | WHITE => "text-primary-charcoal"
  };
};

let bodyTextClass = [%bs.raw {| css(tw`
  pt-8
  text-sm
  font-light
`)
|}];

let orientationToTextClass = (orientation) => {
  switch(orientation) {
  | LEFT => Utils.CssGrid.columnRangeClass(1, 5)
  | RIGHT => Utils.CssGrid.columnRangeClass(11, 15)
  | CENTER => Utils.CssGrid.columnRangeClass(6, 10)
  }
};

let internalTextClass = [%bs.raw {| css(tw`
  text-lg
  font-medium	
`)
|}];

let orientationToImageClass = (orientation) => {
  switch(orientation) {
  | LEFT => Utils.CssGrid.columnRangeClass(7, 15)
  | RIGHT => Utils.CssGrid.columnRangeClass(1, 9)
  | CENTER => Utils_Css.toClass(" display: none; ") /* No image on center */
  }
};

let colorToSplashClass = (color) => {
  switch(color){
    | STEEL => cx(colorTextSwitch(color), "bg-primary-charcoal")
    | GREY => cx(colorTextSwitch(color), [%bs.raw {| css(tw` bg-white`)|}])
    | WHITE => cx(colorTextSwitch(color), "bg-primary-white")
    }
};

/* */
let make = (
  ~title,
  ~body,
  ~image=None,
  ~color=STEEL,
  ~rowClass,
  ~orientation,
  _children
) => {
  ...component,
  render: _self =>
    <Section
      title
      splashClass=cx(colorToSplashClass(color), splashClass)
      textClass=cx(orientationToTextClass(orientation), internalTextClass)
      rowClass
      image
      imageClass=orientationToImageClass(orientation)
      logoShow=(
        switch(orientation){
        | RIGHT => RIGHT
        | LEFT => LEFT
        | CENTER => NONE
        }
      )
    >
      <div className=cx(bodyTextClass, cx("markdownClass", colorTextSwitch(color)))>
        <Bodytext html_=body  />
      </div>
    </Section>
};