[@bs.module "@react-website-themes/default/components/Hero"]
external comp: ReasonReact.reactClass = "default";

let make = (~heroHTML, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={"html": heroHTML},
    children,
  );