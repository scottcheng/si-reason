let component = ReasonReact.statelessComponent("BoardBase");

let columnKey = (x, y) => {j|$x-$y|j};

let markerId = (x, y) => {j|BoardBase-marker-$x-$y|j};

let boardPadding = 0.125;

let position = (x) =>
  string_of_float(
    (
      boardPadding
      +. (1.0 -. boardPadding *. 2.0)
      /. float_of_int(Board.numRows - 1)
      *. float_of_int(x)
    )
    *. 100.0
  )
  ++ "%";

let baseTransform = (rotation, winning) =>
  "translate3d(-50%, -50%, -10000px) rotateX(62deg) rotateZ("
  ++ (string_of_int(rotation + 16 + (winning ? 3600 : 0)) ++ "deg)");

let make = (~rotation, ~winning, _children) => {
  ...component,
  render: (_self) =>
    <div
      className=("BoardBase" ++ (winning ? " BoardBase--winning" : ""))
      style=(
        ReactDOMRe.Style.make(~transform=baseTransform(rotation, winning), ())
      )>
      (
        Board.ijList
        |> List.map(
             ((x, y)) =>
               <div
                 className="BoardBase-mark"
                 key=(columnKey(x, y))
                 id=(markerId(x, y))
                 style=(
                   ReactDOMRe.Style.make(
                     ~position="absolute",
                     ~top=position(x),
                     ~left=position(y),
                     ()
                   )
                 )
               />
           )
        |> Array.of_list
        |> ReasonReact.arrayToElement
      )
    </div>
};
