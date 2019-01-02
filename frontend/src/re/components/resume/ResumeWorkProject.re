let component = ReasonReact.statelessComponent("ResumeWorkProject");
let resumeWorkExperienceTitleStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~fontWeight="600",
    ~fontSize="14",
    (),
  );

let resumeWorkExperienceTimeWrapperStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~marginBottom="5",
    (),
  );

let resumeWorkExperienceTimeStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~fontSize="6",
    (),
  );

let resumeWorkExperienceRoleWrapperStyle =
  ReactPdfStyleSheet.createStyleSheet(
    (),
  );

let resumeWorkExperienceRoleStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~fontWeight="900",
    ~color="dimgrey",
    (),
  );

let make = (~work: PagePropType.nodeType, _children) => {
  ...component,
  render: (_self) => {
    <ReactPdfView>
      <ReactPdfView>
        <ReactPdfText style=resumeWorkExperienceTitleStyle>
          {ReasonReact.string(work##frontmatter##title)}
        </ReactPdfText>
      </ReactPdfView>
      <ReactPdfView style=resumeWorkExperienceRoleWrapperStyle>
        <ReactPdfText style=resumeWorkExperienceRoleStyle>
          {ReasonReact.string(work##frontmatter##role)}
        </ReactPdfText>
      </ReactPdfView>
      <ReactPdfView style=resumeWorkExperienceTimeWrapperStyle>
        <ReactPdfText style=resumeWorkExperienceTimeStyle>
          {ReasonReact.string(work##frontmatter##startTime ++ " - "++ work##frontmatter##endTime)}
        </ReactPdfText>
      </ReactPdfView>
      <ReactPdfView>
        <ReactPdfText>{ReasonReact.string(work##excerpt)}</ReactPdfText>
      </ReactPdfView>
    </ReactPdfView>
  }
};