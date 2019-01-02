type styleObj;
type tailwindFn = string => styleObj;
type emotionFn = styleObj => string;

[@bs.module "emotion"] external css: emotionFn = "css";
[@bs.module "emotion"] external cx: (string, string) => string = "cx";

[@bs.val] external tw: tailwindFn = "";