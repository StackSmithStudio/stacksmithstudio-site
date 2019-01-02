[@bs.module "@react-pdf/renderer"]
external comp: ReasonReact.reactClass = "Page";

let make = (~style: option(ReactPdfStyleSheet.styleSheet)=?, ~size: string, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={
      "size": size,
      "style": style |> Js.Nullable.fromOption,
    },
    children,
  );