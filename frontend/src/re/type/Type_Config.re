type base = {
  .
  "name": string,
  "url": string,
};

type config = {
  .
  "siteTitle": string,
  "siteTitlePostfix": string,
  "siteDescription": string,
  "siteImage": string,
  "siteLanguage": string,
  "headerTitle": string,
  "headerSubTitle": string,
  "siteUrl": string,
  "pathPrefix": option(string),
};

type menuItem = {
  .
  "label": string,
  "to": string,
  "icon": ReasonReact.reactElement,
};

[@bs.get] external getTo: menuItem => string = "to";
let to_ = x => getTo(x);

type menu = array(menuItem);