[@bs.module "@react-pdf/renderer"]
external comp: ReasonReact.reactClass = "Text";

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