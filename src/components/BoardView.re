/* Module called BoardView to avoid conflicting filename with the board logic module */
[@bs.val]
external requestAnimationFrame: (unit => unit) => unit =
  "requestAnimationFrame";

[@bs.val]
external getElementById: string => Dom.element = "document.getElementById";

let columnKey = (x, y) => {j|$x-$y|j};

let columnBaseTransform = ((x, y)) =>
  "translate("
  ++ Js.Float.toString(x)
  ++ "px, "
  ++ Js.Float.toString(y)
  ++ "px)";

let emptyColumnPositions =
  (0., 0.) |> Array.make_matrix(Board.numRows, Board.numRows);

type state = {columnPositions: array(array((float, float)))};

type actions =
  | UpdateColumnPositions;

[@react.component]
let make = (~rotation, ~board, ~move) => {
  let (state, dispatch) =
    React.useReducer(
      (_, action) =>
        switch (action) {
        | UpdateColumnPositions => {
            columnPositions:
              emptyColumnPositions
              |> Array.mapi((x, row) =>
                   row
                   |> Array.mapi((y, _) => {
                        let rect =
                          ReactDOM.domElementToObj(
                            getElementById(BoardBase.markerId(x, y)),
                          )##getBoundingClientRect();
                        (rect##left, rect##top);
                      })
                 ),
          }
        },
      {columnPositions: emptyColumnPositions},
    );
  React.useEffect0(() => {
    let rec onAnimationFrame = () => {
      ignore(dispatch(UpdateColumnPositions));
      requestAnimationFrame(onAnimationFrame);
    };
    requestAnimationFrame(onAnimationFrame);
    None;
  });
  <div className="Board">
    <BoardBase
      rotation
      winning={
        switch (Board.winner(board)) {
        | Some(_) => true
        | None => false
        }
      }
    />
    {Board.ijList
     /* Figure out order in render perspective */
     |> List.sort(((x1, y1), (x2, y2)) => {
          let (_, yPx1) = state.columnPositions[x1][y1];
          let (_, yPx2) = state.columnPositions[x2][y2];
          int_of_float(yPx1) - int_of_float(yPx2);
        })
     |> List.mapi((i, (x, y)) => (i, (x, y)))
     /* Put columns back in stable order, otherwise they rerender everytime */
     |> List.sort(((_, (x1, y1)), (_, (x2, y2))) =>
          x1 == x2 ? y1 - y2 : x1 - x2
        )
     |> List.map(((i, (x, y))) =>
          <div
            className="Board-columnContainer"
            key={columnKey(x, y)}
            style={ReactDOM.Style.make(
              ~transform=columnBaseTransform(state.columnPositions[x][y]),
              ~opacity=
                Js.Float.toString(float_of_int(i) /. 16. *. 0.5 +. 0.5),
              ~zIndex=string_of_int(i),
              (),
            )}>
            <Column
              board
              x
              y
              tryMove={_ =>
                if (Board.isValidMove((x, y), board)) {
                  move((x, y));
                }
              }
              winner={Board.winner(board)}
            />
          </div>
        )
     |> Array.of_list
     |> React.array}
  </div>;
};
