[@bs.module "@react-website-themes/default/components/List"]
external comp: ReasonReact.reactClass = "default";

let make = (~items, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={"items": items},
    children,
  );