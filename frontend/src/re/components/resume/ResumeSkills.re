let component = ReasonReact.statelessComponent("ResumeSkills");

let headerStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~flexWrap="wrap",
    ~display="flex",
    ~flexDirection="row",
    (),
  );

let skillBubbleStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~paddingTop="3",
    ~paddingLeft="3",
    ~paddingRight="3",
    ~borderRadius="2",
    ~backgroundColor="teal",
    ~color="white",
    ~width="auto",
    ~marginLeft="3",
    ~marginBottom="3",
    (),
  );
let make = (~skills: list(string), _children) => {
  ...component,
  render: _self => {
    <ReactPdfView style=headerStyle>
      {
        skills
        |> Belt.List.map(_, (skill) =>
            <ReactPdfView key=skill style=skillBubbleStyle>
              <ReactPdfText>
                {ReasonReact.string(skill)}
              </ReactPdfText>
            </ReactPdfView>
          )
        |> Belt.List.toArray
        |> ReasonReact.array
      }
    </ReactPdfView>
  }
};