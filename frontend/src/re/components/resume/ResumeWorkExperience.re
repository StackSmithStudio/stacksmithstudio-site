let component = ReasonReact.statelessComponent("ResumeWorkExperience");

let resumeWorkProjectStyle = ReactPdfStyleSheet.createStyleSheet(
  ~marginBottom="12",
  (),
);

let make = (~works: list(PagePropType.nodeType), _children) => {
  ...component,
  render: (_self) => {
    <ReactPdfView>
      {
        works
        |> Belt.List.map(_, (work) =>
            <ReactPdfView key=work##id style=resumeWorkProjectStyle>
              <ResumeWorkProject work />
            </ReactPdfView>
        )
        |> Belt.List.toArray
        |> ReasonReact.array
      }
    </ReactPdfView>
  }
};