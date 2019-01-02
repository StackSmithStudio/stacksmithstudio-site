/* TODO Test this in SAFARI!!! */

/* [@bs.module "gatsby-mdx/mdx-renderer"]
external comp: ReasonReact.reactClass = "default";

[@bs.deriving jsConverter]
type components = {
  h1: option(ReasonReact.reactClass),
  h2: option(ReasonReact.reactClass),
  h3: option(ReasonReact.reactClass),
  p: option(ReasonReact.reactClass),
}; */
/* functions componentsToJs and componentsFromJs */
/* 
let defaultComponents = {
  h1: None,
  h2: None,
  h3: None,
  p: None,
}; */

/* h1,
  h2,
  h3,
  h4,
  h5,
  h6,
  a,
  p,
  blockquote,
  ul,
  ol,
  li,
  pre: props => props.children,
  code,
  inlineCode,
  img,
  table */


/* 
let make = (~components=?, children) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={
      "components":
        components
        |> Belt.Option.map(_, componentsToJs)
        |> Js.Nullable.fromOption
    },
    children,
  );
}; */
