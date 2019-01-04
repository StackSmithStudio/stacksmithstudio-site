let css = Css.css;

let hiddenOpacity = [%bs.raw {| css(tw` opacity-0 h-0 `)|}];

let classTransitionIn = (waypointEntered) => waypointEntered ? "" : hiddenOpacity;
let classTransitionInWithPrevClass = (waypointEntered, prevClass) => waypointEntered ? "" : prevClass;

let polishTransitionStyle = (styleString : string) =>
  Polished.singleStylesToClass(Polished.transitions, styleString);



