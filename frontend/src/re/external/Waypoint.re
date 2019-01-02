[@bs.module "react-waypoint"]
external comp: ReasonReact.reactClass = "default";

let make = (~onEnter, ~wayKey, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={
      "key": wayKey,
      "onEnter": onEnter
    },
    children,
  );
