[@bs.module "@react-website-themes/default/components/Heading"]
external comp: ReasonReact.reactClass = "default";

let make = (~title=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={"title": Js.Nullable.fromOption(title)},
    children,
  );