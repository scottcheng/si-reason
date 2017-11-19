let component = ReasonReact.statelessComponent("Column");

let make = (~beads, ~canMove, ~tryMove, _children) => {
  ...component,
  render: (_self) =>
    <div
      className=(canMove ? "Column Column--canMove" : "Column")
      onClick=tryMove>
      (
        beads
        |> Array.mapi(
             (i, el) =>
               switch el {
               | None => ReasonReact.nullElement
               | Some(Board.P1) =>
                 <Bead key=(string_of_int(i)) player=Board.P1 />
               | Some(Board.P2) =>
                 <Bead key=(string_of_int(i)) player=Board.P2 />
               }
           )
        |> ReasonReact.arrayToElement
      )
    </div>
};
