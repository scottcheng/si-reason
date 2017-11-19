let component = ReasonReact.statelessComponent "Column";

let make ::x ::y ::board ::move _children => {
  ...component,
  render: fun _self =>
    <div
      className="Column"
      onClick=(
                fun _ =>
                  if (Board.isValidMove (x, y) board) {
                    move ()
                  }
              )>
      (
        board |> Array.map (fun layer => layer.(x).(y)) |>
        Array.mapi (
          fun i el =>
            switch el {
            | None => ReasonReact.nullElement
            | Some Board.P1 => <Bead key=(string_of_int i) player=Board.P1 />
            | Some Board.P2 => <Bead key=(string_of_int i) player=Board.P2 />
            }
        ) |> ReasonReact.arrayToElement
      )
    </div>
};
