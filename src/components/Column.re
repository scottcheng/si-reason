let component = ReasonReact.statelessComponent "Column";

let make ::i ::j ::gameState ::move _children => {
  ...component,
  render: fun _self =>
    <div
      className="Column"
      onClick=(
                fun _ =>
                  if (Engine.isValidMove (i, j) gameState) {
                    move ()
                  }
              )>
      (
        gameState |> Array.map (fun layer => layer.(i).(j)) |>
        Array.mapi (fun i el => <Bead key=(string_of_int i) el />) |> ReasonReact.arrayToElement
      )
    </div>
};
