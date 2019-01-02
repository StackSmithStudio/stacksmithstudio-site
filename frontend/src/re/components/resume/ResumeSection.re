let component = ReasonReact.statelessComponent("ResumeSection");

let sectionStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~width="100%",
    ~paddingLeft="20",
    ~paddingRight="20",
    (),
  );
let sectionInnerWrapperStyle =
ReactPdfStyleSheet.createStyleSheet(
  ~display="flex",
  ~flexDirection="row",
  ~justifyContent="flex-between",
  ~borderBottomWidth="1",
  ~borderBottomColor="lightgrey",
  ~paddingTop="15",
  ~paddingBottom="10",
  (),
);

let titleWrapperStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~width="20%",
    (),
  );

let titleTextStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~fontSize="12",
    ~fontWeight="800",
    ~color="gold",
    (),
  );
let contactSectionWrapperStyle =
ReactPdfStyleSheet.createStyleSheet(
  ~width="80%",
  ~paddingRight="30",
  (),
);

let make = (~title, children) => {
  ...component,
  render: _self => {
    <ReactPdfView style=sectionStyle>
      <ReactPdfView style=sectionInnerWrapperStyle>
        <ReactPdfView style=titleWrapperStyle>
          <ReactPdfText style=titleTextStyle>{ReasonReact.string(title)}</ReactPdfText>
        </ReactPdfView>
        <ReactPdfView style=contactSectionWrapperStyle>
          {children}
        </ReactPdfView>
      </ReactPdfView>
    </ReactPdfView>
  }
};