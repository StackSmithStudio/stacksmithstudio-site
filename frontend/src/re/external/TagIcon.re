[@bs.module "react-feather/dist/icons/tag"]
external comp: ReasonReact.reactClass = "default";

let make = children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props=Js.Obj.empty(),
    children,
  );