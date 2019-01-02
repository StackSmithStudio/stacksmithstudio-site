[@bs.module "@react-pdf/renderer"]
external comp: ReasonReact.reactClass = "Document";

let make = (children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props=Js.Obj.empty(),
    children,
  );