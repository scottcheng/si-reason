let component = ReasonReact.statelessComponent "BoardBase";

let columnKey x y => {j|$x-$y|j};

let markerId x y => {j|BoardBase-marker-$x-$y|j};

let boardPadding = 0.125;

let position x =>
  string_of_float (
    (
      boardPadding +.
      (1.0 -. boardPadding *. 2.0) /. float_of_int (Engine.numRows - 1) *. float_of_int x
    ) *. 100.0
  ) ^ "%";

/* TODO: tweak perspective */
let baseTransform rotation =>
  "translate3d(-50%, -50%, -10000px) rotateX(60deg) rotateZ(" ^
  string_of_int (rotation + 20) ^ "deg)";

let make ::rotation _children => {
  ...component,
  render: fun _self =>
    <div
      className="BoardBase" style=(ReactDOMRe.Style.make transform::(baseTransform rotation) ())>
      (
        Engine.ijList |>
        List.map (
          fun (x, y) =>
            <div
              className="BoardBase-mark"
              key=(columnKey x y)
              id=(markerId x y)
              style=(
                      ReactDOMRe.Style.make
                        position::"absolute" top::(position x) left::(position y) ()
                    )
            />
        ) |> Array.of_list |> ReasonReact.arrayToElement
      )
    </div>
};
