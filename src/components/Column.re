[@react.component]
let make = (~board, ~x, ~y, ~tryMove, ~winner) => {
  <div
    className={Util.cx([
      ("Column", true),
      ("Column--canMove", Board.isValidMove((x, y), board)),
    ])}
    onClick=tryMove>
    {board
     |> Array.map(layer => layer[x][y])
     |> Array.mapi((i, el) => {
          let winning =
            switch (winner) {
            | Some((_, positions))
                when positions |> List.exists(pos => pos == (i, x, y)) =>
              true
            | _ => false
            };
          switch (el) {
          | None => React.null
          | Some(Board.P1) =>
            <Bead key={string_of_int(i)} player=Board.P1 winning />
          | Some(Board.P2) =>
            <Bead key={string_of_int(i)} player=Board.P2 winning />
          };
        })
     |> React.array}
  </div>;
};
