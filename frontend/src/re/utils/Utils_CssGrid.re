let fullName = "full";
let mainName = "main";

let numColumns = 14;

let gridClass = (numMainRows) =>
 /* need this until subgrid */
  Utils_Css.toClass("
    display: grid;

    grid-template-columns:
      [" ++ fullName ++ "-start]
      minmax(1em, 4fr)
      [" ++ mainName ++ "-start]
      repeat(12, [col] minmax(0, 4em))
      [" ++ mainName ++ "-end]
      minmax(1em, 4fr)
      [" ++ fullName ++ "-end];

    grid-template-rows:
      [menu-start]
      4rem
      [menu-end intro]
      minmax(32rem, 100vh)
      "
      ++ "repeat(" ++ string_of_int(numMainRows) ++ ", [row-start] minmax(32rem, auto) [row-end])" ++
      "
      [footer-start]
      minmax(32rem, 100vh)
      [footer-end];

    & > * {
      grid-column: "  ++ fullName ++ ";
    }
  ");

let menuRowClass = Utils_Css.toClass("
  {
    grid-row: menu;
  }
");

let rowClassName = (row) => Utils_Css.toClass("
  grid-row: row-start " ++ string_of_int(row) ++ ";
");

let rowIntroClass = Utils_Css.toClass("
  {
    grid-row: intro;
  }
");

let rowFooterClass = Utils_Css.toClass("
  {
    grid-row: footer;
  }
");


let proseClass = Utils_Css.toClass("
    {
      grid-column: " ++ mainName ++ ";
    }
  ");

let splashClass =
  Utils_Css.toClass("
    {
      grid-column: " ++ fullName ++ ";
    }
  ");
