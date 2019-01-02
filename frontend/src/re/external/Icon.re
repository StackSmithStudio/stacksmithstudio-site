let make = (~comp, ~className=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={"className": Js.Nullable.fromOption(className)},
    children,
  );