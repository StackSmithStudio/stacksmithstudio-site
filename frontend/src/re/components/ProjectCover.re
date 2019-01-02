let component = ReasonReact.statelessComponent("ProjectCover");

let css = Css.css;
let tw = Css.tw;

let projectCoverClass = [%bs.raw {| css(tw`
  h-full
`)
|}];

let projectCoverImageClass = [%bs.raw {| css(tw`
  w-full
`) |}];

let make = (~project, _children) => {
  ...component,
  render: _self =>
    <div className=projectCoverClass>
      <img
        className=projectCoverImageClass
        src=project##node##frontmatter##cover##publicURL
      />
    </div>,
};