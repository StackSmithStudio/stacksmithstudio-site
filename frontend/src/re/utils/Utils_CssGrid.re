let fullName = "full";
let mainName = "main";

let numberRows = 14;
let gridClass =
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
      [menu]
      4rem
      [intro]
      100vh
      repeat(auto-fill, [row] 100vh)
      [footer];

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
  grid-row: row " ++ string_of_int(row) ++ ";
");

let rowIntroClass = Utils_Css.toClass("
  {
    grid-row: intro;
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
