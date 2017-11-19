/* Module called BoardView to avoid conflicting filename with the board logic module */
external requestAnimationFrame : (unit => unit) => unit = "" [@@bs.val];

external getElementById : string => Dom.element = "document.getElementById" [@@bs.val];

let columnKey x y => {j|$x-$y|j};

let columnBaseTransform (x, y) =>
  "translate(" ^ string_of_float x ^ "px, " ^ string_of_float y ^ "px)";

let emptyColumnPositions = (0., 0.) |> Array.make_matrix Board.numRows Board.numRows;

type state = {columnPositions: array (array (float, float))};

type actions =
  | UpdateColumnPositions;

let component = ReasonReact.reducerComponent "Board";

let make ::rotation ::board ::move _children => {
  ...component,
  initialState: fun () => {columnPositions: emptyColumnPositions},
  reducer: fun action _ =>
    switch action {
    | UpdateColumnPositions =>
      ReasonReact.Update {
        columnPositions:
          emptyColumnPositions |>
          Array.mapi (
            fun x row =>
              row |>
              Array.mapi (
                fun y _ => {
                  let rect =
                    (ReactDOMRe.domElementToObj (getElementById (BoardBase.markerId x y)))##getBoundingClientRect
                      ();
                  (rect##left, rect##top)
                }
              )
          )
      }
    },
  didMount: fun {reduce} => {
    let rec onAnimationFrame () => {
      reduce (fun _ => UpdateColumnPositions) ();
      requestAnimationFrame onAnimationFrame
    };
    requestAnimationFrame onAnimationFrame;
    ReasonReact.NoUpdate
  },
  render: fun {state: {columnPositions}} =>
    <div className="Board">
      <BoardBase rotation />
      (
        Board.ijList |>
        List.map (
          fun (x, y) =>
            <div
              className="Board-columnContainer"
              key=(columnKey x y)
              style=(
                      ReactDOMRe.Style.make
                        transform::(columnBaseTransform columnPositions.(x).(y)) ()
                    )>
              <Column x y board move=(fun _ => move (x, y)) />
            </div>
        ) |> Array.of_list |> ReasonReact.arrayToElement
      )
    </div>
};
