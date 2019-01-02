let component = ReasonReact.statelessComponent("Resume");

let css = Css.css;
let tw = Css.tw;

let resumePageStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~padding="30",
    (),
  );


let resumeStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~width="100%",
    ~fontSize="10",
    ~color="grey",
    (),
  );

let headerSectionStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~height="100",
    ~width="100%",
    ~borderBottomWidth="2",
    ~borderColor="gold",
    (),
  );

let contentSectionStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~width="100%",
    (),
  );

let hasJobType = (projects, jobTypeName) =>
  projects##edges
  |> Belt.List.fromArray
  |> Belt.List.keep(_, edge => {
      (
        edge##node##frontmatter##jobType
        |> Belt.List.fromArray
        |> Belt.List.keep(_, (jobType) => jobType == jobTypeName)
        |> Belt.List.length
   ) > 0
  })
  |> Belt.List.map(_, edge => edge##node);

let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: _self => {
    let works = hasJobType(props##data##projects, "job");
    let contractWorks = hasJobType(props##data##projects, "contract");
    let educations = hasJobType(props##data##projects, "education");
    let volunteerWorks = hasJobType(props##data##projects, "volunteer");

    let categories =
      (works @ contractWorks @ educations @ volunteerWorks)
      |> Belt.List.map(_, (work) => Belt.List.fromArray(work##frontmatter##categories))
      |> Belt.List.flatten
      |> Belt.List.toArray
      |> Belt.HashSet.String.fromArray
      |> Belt.HashSet.String.toArray
      |> Belt.List.fromArray;
      
    <ReactPdfDocument>
      <ReactPdfPage size="A4" style=resumePageStyle>
        <ReactPdfView style=resumeStyle>
          <ReactPdfView style=headerSectionStyle>
            <ResumeHeader/>
          </ReactPdfView>
          <ReactPdfView style=contentSectionStyle>
            <ResumeSection title="Personal Profile">
              <ReactPdfText key="profile">{ReasonReact.string(Helper_Me.resumeAbout)}</ReactPdfText>
            </ResumeSection>
            <ResumeSection title="Work Experience">
              <ResumeWorkExperience key="work" works=works />
            </ResumeSection>
            <ResumeSection title="Contract Work">
              <ResumeWorkExperience key="contracts" works=contractWorks />
            </ResumeSection>
            <ResumeSection title="Education">
              <ResumeWorkExperience key="education" works=educations />
            </ResumeSection>
            <ResumeSection title="Volunteering">
              <ResumeWorkExperience key="volunteer" works=volunteerWorks />
            </ResumeSection>
            <ResumeSection title="Skills">
              <ResumeSkills key="skills" skills=categories />
            </ResumeSection>
          </ReactPdfView>
        </ReactPdfView>
      </ReactPdfPage>
    </ReactPdfDocument>;
  }
};