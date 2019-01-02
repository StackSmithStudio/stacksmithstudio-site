[@bs.module "../../../../../src/spectacleSlides"]
external comp: ReasonReact.reactClass = "default";

let make = (
  ~markdown: string,
  _children
) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={
      "markdown": markdown,
    },
    _children,
  );
};