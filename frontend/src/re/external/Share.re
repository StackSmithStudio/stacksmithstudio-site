[@bs.module "@react-website-themes/default/components/Share"]
external comp: ReasonReact.reactClass = "default";

let make = (~shareBlockProps, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={"shareBlockProps": shareBlockProps},
    children,
  );