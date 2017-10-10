let se = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent "BoardBase";

let columnKey i j => {j|$i-$j|j};

let markerId i j => {j|BoardBase-marker-$i-$j|j};

let position i =>
  string_of_float (
    (
      Const.boardPadding +.
      (1.0 -. Const.boardPadding *. 2.0) /. float_of_int (Const.numRows - 1) *. float_of_int i
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
        Const.ijList |>
        List.map (
          fun (i, j) =>
            <div
              className="BoardBase-mark"
              key=(columnKey i j)
              id=(markerId i j)
              style=(
                      ReactDOMRe.Style.make
                        position::"absolute" top::(position i) left::(position j) ()
                    )
            />
        ) |> Array.of_list |> ReasonReact.arrayToElement
      )
    </div>
};
