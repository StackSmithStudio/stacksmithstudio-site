let component = ReasonReact.statelessComponent("ProjectModalContent");

let css = Css.css;
let tw = Css.tw;

let projectModalContentClass = [%bs.raw
  {| css(tw`
  h-full
  w-full
  overflow-y-scroll
  max-h-screen
`)
|}
];

let projectModelHtmlClass = [%bs.raw
  {| css(tw`
  border-0
  border-b-2
  border-t-2
  py-2
  my-1
  border-grey-light
  border-solid
  w-full
  `)
  |}
];

let projectModalImageClass = [%bs.raw
  {| css(tw`
  flex
  space-between
  `)
  |}
];

let projectModalTitleClass = [%bs.raw
  {| css(tw`
    flex
    flex-wrap
  `)
  |}
];

let projectModalTextCategoriesClass = [%bs.raw {| css(tw`
  inline
  `)
  |}];

let projectModalTextContentClass = [%bs.raw {| css(tw`
    p-8
  `)
|}];

let projectModalTitleTextClass = [%bs.raw
  {| css(tw`
  w-full
  md:w-1/2
`)
|}
];

let projectModalCategoriesClass = [%bs.raw
  {| css(tw`
  w-full
`)
|}
];

let joinStringList = (listString: list(string), glue: string): string =>
  Belt.List.reduce(listString, "", (memo, ele) =>
    memo ++ (memo == "" ? ele : glue ++ ele)
  );

let make = (~project, _children) => {
  ...component,
  render: _self =>
    <div className=projectModalContentClass>
      <div className=projectModalImageClass> <ProjectCover project /> </div>
      <div className=projectModalTextContentClass>
        <div className=projectModalTitleClass>
          <h3 className=projectModalTitleTextClass>
            {ReasonReact.string(project##node##frontmatter##title)}
          </h3>
        </div>
        <div className=projectModelHtmlClass dangerouslySetInnerHTML={"__html": project##node##html} />
        <div className=projectModalCategoriesClass>
          <h4 className=projectModalTextCategoriesClass>
            {ReasonReact.string("Categories: ")}
          </h4>
          {
            project##node##frontmatter##categories
            |> Belt.List.fromArray
            |> joinStringList(_, ", ")
            |> ReasonReact.string
          }
        </div>
      </div>
    </div>,
};