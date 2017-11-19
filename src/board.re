let numRows = 4;

let iList = [0, 1, 2, 3];

let ijList = iList |> List.map (fun i => iList |> List.map (fun j => (i, j))) |> List.flatten;

let ijkList =
  ijList |> List.map (fun (i, j) => iList |> List.map (fun k => (i, j, k))) |> List.flatten;

type player =
  | P1
  | P2;

type state = array (array (array (option player)));

let emptyState: state = None |> Array.make numRows |> Array.make numRows |> Array.make numRows;

let winner state => {
  /* Pair of coordinates at two ends of 4 consecutive places */
  let allPairs =
    ijkList |>
    List.map (
      fun (z1, x1, y1) => ijkList |> List.map (fun (z2, x2, y2) => ((z1, x1, y1), (z2, x2, y2)))
    ) |> List.flatten |>
    List.filter (
      fun ((z1, x1, y1), (z2, x2, y2)) =>
        (z1 != z2 || x1 != x2 || y1 != y2) &&
        [z1 - z2, x1 - x2, y1 - y2] |> List.for_all (fun d => d mod (numRows - 1) == 0)
    );
  let interpolate a b i => (b - a) / (numRows - 1) * i + a;
  let checkWinner p ((z1, x1, y1), (z2, x2, y2)) =>
    iList |>
    List.map (fun i => state.(interpolate z1 z2 i).(interpolate x1 x2 i).(interpolate y1 y2 i)) |>
    List.for_all (fun el => el == Some p);
  let checkWinnerInAllPairs p => allPairs |> List.exists (checkWinner p);
  switch (checkWinnerInAllPairs P1, checkWinnerInAllPairs P2) {
  | (true, true) => None
  | (true, false) => Some P1
  | (false, true) => Some P2
  | (false, false) => None
  }
};

let isFull state => ijList |> List.for_all (fun (x, y) => state.(numRows - 1).(x).(y) != None);

let isEnd state => winner state != None || isFull state;

let isValidMove (x, y) state => not (isEnd state) && state.(numRows - 1).(x).(y) == None;

let move (x, y) player state =>
  isValidMove (x, y) state ?
    {
      let putPieceOnLayer (x, y) player layer => {
        let newLayer = layer |> Array.map (fun row => Array.copy row);
        newLayer.(x).(y) = Some player;
        newLayer
      };
      let (newState, _) =
        Array.fold_left
          (
            fun (curState, hasPlaced) layer =>
              not hasPlaced && layer.(x).(y) == None ?
                (Array.append curState [|putPieceOnLayer (x, y) player layer|], true) :
                (Array.append curState [|layer|], hasPlaced)
          )
          ([||], false)
          state;
      newState
    } :
    state;
