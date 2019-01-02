[@bs.module "@react-pdf/renderer"]
external comp: ReasonReact.reactClass = "View";

/* Note: these do not take className */
let make = (~style: option(ReactPdfStyleSheet.styleSheet)=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={
      "style":
        style |> Js.Nullable.fromOption,
    },
    children,
  );