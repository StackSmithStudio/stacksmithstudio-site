type polishedObj;
type polishedArguments = array(string);
type applied = (polishedArguments => Css.styleObj);

[@bs.send] external applyReal: (polishedObj, Js.Dict.t(string), polishedArguments) => Css.styleObj = "apply";
let apply = (polishedObj, polishedArguments) => applyReal(polishedObj, Js.Dict.empty(), polishedArguments);

[@bs.module "polished"] external transitionsObj: polishedObj = "transitions";

let transitions: applied = apply(transitionsObj);

let singleStylesToClass = (applied : applied, string: string) =>
  [|string|] |> applied |> Css.css;
  

