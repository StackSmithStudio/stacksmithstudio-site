[@bs.module "@react-website-themes/default/components/Comments"]
external comp: ReasonReact.reactClass = "default";

let make = (~slug, ~siteUrl, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={"slug": slug, "siteUrl": siteUrl},
    children,
  );