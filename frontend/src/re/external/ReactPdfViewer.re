[@bs.module "@react-pdf/renderer"]
external comp: ReasonReact.reactClass = "PDFViewer";

let make = (~className="", children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={
      "className": className
    },
    children,
  );