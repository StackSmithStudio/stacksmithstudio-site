[@bs.module "@react-website-themes/default/components/NextPrev"]
external comp: ReasonReact.reactClass = "default";

let make = (~next, ~prev, ~icons, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={"next": next, "prev": prev, "icons": icons},
    children,
  );