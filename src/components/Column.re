let component = ReasonReact.statelessComponent "Column";

let make ::x ::y ::gameState ::move _children => {
  ...component,
  render: fun _self =>
    <div
      className="Column"
      onClick=(
                fun _ =>
                  if (Engine.isValidMove (x, y) gameState) {
                    move ()
                  }
              )>
      (
        gameState |> Array.map (fun layer => layer.(x).(y)) |>
        Array.mapi (fun i el => <Bead key=(string_of_int i) el />) |> ReasonReact.arrayToElement
      )
    </div>
};
