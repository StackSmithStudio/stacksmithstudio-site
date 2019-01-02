[@bs.module "@react-website-themes/default/components/Bodytext"]
external comp: ReasonReact.reactClass = "default";

let make = (~html_, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={"html": html_},
    children,
  );