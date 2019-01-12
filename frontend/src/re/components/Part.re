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
`)
|}];

let orientationToTextClass = (orientation) => {
  switch(orientation) {
  | LEFT => Utils.CssGrid.columnRangeClass(1, 4)
  | RIGHT => Utils.CssGrid.columnRangeClass(10, 14)
  | CENTER => Utils.CssGrid.columnRangeClass(5, 10)
  }
};

let orientationToImageClass = (orientation) => {
  switch(orientation) {
  | LEFT => Utils.CssGrid.columnRangeClass(8, 14)
  | RIGHT => Utils.CssGrid.columnRangeClass(1, 6)
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
      textClass=orientationToTextClass(orientation)
      rowClass
      image
      imageClass=orientationToImageClass(orientation)
    >
      <div className=cx(bodyTextClass, cx("markdownClass", colorTextSwitch(color)))>
        <Bodytext html_=body  />
      </div>
    </Section>
};