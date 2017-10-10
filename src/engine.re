type el =
  | P1
  | P2
  | Empty;

type state = array (array (array el));

let emptyState =
  Empty |> Array.make Const.numRows |> Array.make Const.numRows |> Array.make Const.numRows;

/* TODO */
let isEnd state => false;

let isValidMove (i, j) state => not (isEnd state) && state.(Const.numRows - 1).(i).(j) == Empty;

let move (i, j) el state =>
  isValidMove (i, j) state ?
    {
      let (newState, _) =
        Array.fold_left
          (
            fun (curState, hasPlaced) layer =>
              not hasPlaced && layer.(i).(j) == Empty ?
                (
                  Array.append
                    curState
                    [|
                      layer |>
                      Array.mapi (
                        fun ii row =>
                          row |> Array.mapi (fun jj curEl => ii == i && jj == j ? el : curEl)
                      )
                    |],
                  true
                ) :
                (Array.append curState [|layer|], hasPlaced)
          )
          ([||], false)
          state;
      newState
    } :
    state;
