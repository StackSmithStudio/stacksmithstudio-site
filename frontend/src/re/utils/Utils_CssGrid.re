let fullName = "full";
let mainName = "main";

let numColumns = 15;

let gridClass = (numMainRows) =>
 /* need this until subgrid */
  Utils_Css.toClass("
    display: grid;

    grid-template-columns:
      [" ++ fullName ++ "-start]
      minmax(4rem, 4fr)
      [" ++ mainName ++ "-start]
      "
      ++ "repeat(" ++ string_of_int(numColumns) ++ ", [col-start] minmax(0, 4rem) [col-end])" ++
      "
      [" ++ mainName ++ "-end]
      minmax(4rem, 4fr)
      [" ++ fullName ++ "-end];

    grid-template-rows:
      /* [menu-start]
      4rem */
      [intro]
      minmax(8rem, 24rem)
      "
      ++ "repeat(" ++ string_of_int(numMainRows) ++ ", [row-start] auto [row-end])" ++
      "
      [footer-start]
      auto
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

let columnClass = (column) => Utils_Css.toClass("
  {
    grid-column: col-start " ++ string_of_int(column) ++ ";
  }
");

let columnRangeClass = (columnBegin, columnEnd) => Utils_Css.toClass("
  {
    grid-column: col-start " ++ string_of_int(columnBegin) ++ " / col-end " ++ string_of_int(columnEnd) ++ ";
  }
");

let columnStartClass = (columnBegin) => Utils_Css.toClass("
  {
    grid-column-start: col-start " ++ string_of_int(columnBegin) ++ ";
  }
");

let columnEndClass = (columnBegin) => Utils_Css.toClass("
  {
    grid-column-end: col-end " ++ string_of_int(columnBegin) ++ ";
  }
");

let columnFullEndClass = Utils_Css.toClass("
  {
    grid-column-end: full-end;
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
