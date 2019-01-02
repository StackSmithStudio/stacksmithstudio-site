[@bs.module "spectacle-image-slide"]
external comp: ReasonReact.reactClass = "default";

let make = (~image, ~title, children: array(ReasonReact.reactElement)) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={
      "title": title,
      "image": image,
    },
    children,
  );
};

let default =
  ReasonReact.wrapReasonForJs(jsProps =>
    make(~title=jsProps##title, ~image=jsProps##image, [||])
  );