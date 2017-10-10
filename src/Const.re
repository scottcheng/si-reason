let numRows = 4;

let boardPadding = 0.125;

let ijList =
  [0, 1, 2, 3] |> List.map (fun i => [0, 1, 2, 3] |> List.map (fun j => (i, j))) |> List.flatten;
