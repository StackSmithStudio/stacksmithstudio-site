[@bs.module "@react-website-themes/default/components/Meta"]
external comp: ReasonReact.reactClass = "default";

let make = (~author, ~prefix, ~categories, ~icons, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={
      "author": author,
      "prefix": prefix,
      "categories": categories,
      "icons": icons,
    },
    children,
  );