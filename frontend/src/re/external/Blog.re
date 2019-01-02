[@bs.module "@react-website-themes/default/components/Blog"]
external comp: ReasonReact.reactClass = "default";

let make = (~items, ~author, ~metaIcons, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={"items": items, "author": author, "metaIcons": metaIcons},
    children,
  );