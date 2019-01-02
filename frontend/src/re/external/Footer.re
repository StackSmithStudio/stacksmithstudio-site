[@bs.module "@react-website-themes/default/components/Footer"]
external comp: ReasonReact.reactClass = "default";

/* let make = (~links, ~copyright, children) =>
   ReasonReact.wrapJsForReason(
     ~reactClass=comp,
     ~props={"links": links, "copyright": copyright},
     children,
   ); */

let component = ReasonReact.statelessComponent("Footer");

let make = (~links, ~copyright, children) => {
  ...component,
  render: _self => <div />,
};