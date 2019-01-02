[@bs.module "@react-website-themes/default/components/Article"]
external comp: ReasonReact.reactClass = "default";

let make = children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props=Js.Obj.empty(),
    children,
  );