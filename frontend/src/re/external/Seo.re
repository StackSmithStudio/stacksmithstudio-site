[@bs.module "@react-website-themes/default/components/Seo"]
external comp: ReasonReact.reactClass = "default";

let make = (~url, ~language, ~title, ~description, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={
      "url": url,
      "language": language,
      "title": title,
      "description": description,
    },
    children,
  );