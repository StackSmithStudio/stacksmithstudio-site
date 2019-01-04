let joinStringsWithSeparator = (listOfString : list(string), separator) =>
  listOfString
  |> Belt.List.reduce(_, "", (memo, splitString) => { memo ++ (memo == "" ? "" : separator) ++ splitString });

let slugifyId = (id) => id |> String.lowercase |> Js_string.split(" ", _) |> Belt.List.fromArray |> joinStringsWithSeparator(_, "-");