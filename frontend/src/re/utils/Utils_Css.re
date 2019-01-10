let css = Css.css;
type breakpoint =
  | SM
  | MD
  | LG
  | XL;

/* THIS CAN BE PASSED AS CONFIGURABLE TO MODULE */

let toClass: (string) => string = [%bs.raw {| function (cssString) { return css`${cssString}`; } |} ];

let breakpointToInt = (breakpoint : breakpoint) =>
  switch(breakpoint){
  | SM => 576
  | MD => 768
  | LG => 992
  | XL => 1200
  };

let breakpointToMediaQuery = (bp) => "@media (min-width: " ++ (bp |> breakpointToInt |> string_of_int) ++ "px)";


let cssToEmotionMediaQuery = (breakpoint: breakpoint, cssString: string) =>
  (breakpointToMediaQuery(breakpoint) ++ " { " ++ cssString ++ "} ") |> toClass;

/*
EXAMPLE:
let mediaQueryClassName = Utils.Css.cssToEmotionMediaQuery(Utils.Css.SM, "
  background-color: red;
");

Js.log("mediaQueryClassName = 5j");
Js.log(mediaQueryClassName);
*/
