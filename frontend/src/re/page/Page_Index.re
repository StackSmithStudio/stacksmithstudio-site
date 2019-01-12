[%bs.raw {|require('../../../../../src/styles/styles.css')|}];
[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];
[%bs.raw {|require('tailwindcss/tailwind.css')|}];

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;
let introAreaCss = [%bs.raw
  {| css(tw`
    h-screen
    flex
    flex-col
  `) |}
];

let introAreaClass = [%bs.raw
  {| css(tw`
    h-screen
    flex
    flex-col
  `) |}
];

let heroAreaClass = [%bs.raw
  {| css(tw`
    flex-1
    relative
  `)|}
];

let heroAreaInnerClass = [%bs.raw
{| css(tw`
  pin-t
  pin-l
  absolute
  w-full
  h-full
`)|}
];
/* NOTE this is how you handle safari issue */
/* https://stackoverflow.com/a/33644245/923636 */
/* https://bugs.webkit.org/show_bug.cgi?id=137730 */
let menuAreaClass = [%bs.raw {| css(tw`
  pin-t	
  z-10
`) |}];

let partsAreaClass = [%bs.raw {| css(tw`
  pt-16
`) |}];


let gridClass = Utils.CssGrid.gridClass;

let mediaQueryClassName = Utils.Css.cssToEmotionMediaQuery(Utils.Css.SM, "
  background-color: red;
");

type projectType = option(string);
type state = {projectModal: projectType};

type action =
  | NoOp
  | SelectProject(projectType);

let component = ReasonReact.reducerComponent("Page_Index");

let addOne = (a) => a + 1;

let make = (~props: PagePropType.props, _children) => {
  ...component,
  initialState: () => {projectModal: None},
  reducer: (action, _state) =>
    switch (action) {
    | NoOp => ReasonReact.NoUpdate
    | SelectProject(pid) => ReasonReact.Update({projectModal: pid})
    },
  render: self => {
    let projects = props##data##projects##edges;
    let parts = props##data##parts##edges;
    <Modal
      modalSelect={self.state.projectModal}
      closeFn={() => self.send(SelectProject(None)) |> ignore}
      modalContents={
        modalId => {
          let optionProj =
            projects
            |> Belt.List.fromArray
            |> Belt.List.getBy(_, edge => edge##node##id == modalId);

          Belt.Option.mapWithDefault(optionProj, <div />, projVal =>
            <ProjectModalContent project=projVal />
          );
        }
      }
    >
      <div className=(parts |> Belt.List.fromArray |> Belt.List.length |> gridClass)>
        <Intro
          splashClass=Utils.CssGrid.splashClass
          rowClass=Utils.CssGrid.rowIntroClass
          mainClass=Utils.CssGrid.proseClass
          anvilClass=cx(Utils.CssGrid.columnStartClass(5), Utils.CssGrid.columnFullEndClass)
        />
        {
          parts
          |> Belt.Array.mapWithIndex(_, (index, edge) =>
              <Part
                title=edge##node##frontmatter##title
                body=edge##node##html
                image=None /* find an image*/
                color=(Part.WHITE)
                rowClass=Utils.CssGrid.rowClassName(index |> addOne)
                orientation=(
                  Part.orientations
                  |> Belt.List.get(_, index)
                  |> Belt.Option.getWithDefault(_, Part.CENTER)
                )
              />)
          |> ReasonReact.array
        }
        /* <Projects
          projects
          selectProject={pid => self.send(SelectProject(Some(pid)))}
        /> */
        <Contact rowClass=Utils.CssGrid.rowFooterClass />
        /* <Footer
          links=props##data##footerLinks##html
          copyright=props##data##copyright##html
        />
        <Seo
          url=Config.config##siteUrl
          language=Config.config##siteLanguage
          title=Config.config##siteTitle
          description=Config.config##siteDescription
        /> */
      </div>
    </Modal>;
  },
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );