external requestAnimationFrame : (unit => unit) => unit = "" [@@bs.val];

external getElementById : string => Dom.element = "document.getElementById" [@@bs.val];

let se = ReasonReact.stringToElement;

let columnKey i j => {j|$i-$j|j};

let columnBaseTransform (x, y) =>
  "translate(" ^ string_of_float x ^ "px, " ^ string_of_float y ^ "px)";

let emptyColumnPositions = (0., 0.) |> Array.make_matrix Const.numRows Const.numRows;

type state = {columnPositions: array (array (float, float))};

type actions =
  | UpdateColumnPositions;

let component = ReasonReact.reducerComponent "Board";

let make ::rotation _children => {
  ...component,
  initialState: fun () => {columnPositions: emptyColumnPositions},
  reducer: fun action _ =>
    switch action {
    | UpdateColumnPositions =>
      ReasonReact.Update {
        columnPositions:
          emptyColumnPositions |>
          Array.mapi (
            fun i arr =>
              arr |>
              Array.mapi (
                fun j _ => {
                  let rect =
                    (ReactDOMRe.domElementToObj (getElementById (BoardBase.markerId i j)))##getBoundingClientRect
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
        Const.ijList |>
        List.map (
          fun (i, j) =>
            <div
              className="Board-columnContainer"
              key=(columnKey i j)
              style=(
                      ReactDOMRe.Style.make
                        transform::(columnBaseTransform columnPositions.(i).(j)) ()
                    )>
              <Column i j />
            </div>
        ) |> Array.of_list |> ReasonReact.arrayToElement
      )
    </div>
};
