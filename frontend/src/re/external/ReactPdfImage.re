[@bs.module "@react-pdf/renderer"]
external comp: ReasonReact.reactClass = "Image";

let make = (~src: string, ~style: option(ReactPdfStyleSheet.styleSheet)=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={
      "src": src,
      "style":
        style |> Js.Nullable.fromOption,
    },
    children,
  );