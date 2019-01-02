[@bs.module "spectacle"]
external comp: ReasonReact.reactClass = "Deck";

let make = (~theme : option(Spectacle.theme)=? , children: array(ReasonReact.reactElement)) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={
      "theme": Js.Nullable.fromOption(theme)
    },
    children,
  );
};