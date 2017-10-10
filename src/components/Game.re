let se = ReasonReact.stringToElement;

type place =
  | P1
  | P2
  | Empty;

type gameState = array (array (array place));

type state = {
  rotation: int, /* In degrees */
  gameState
};

type actions =
  | Rotate int
  | Reset;

let component = ReasonReact.reducerComponent "Game";

let make _children => {
  ...component,
  initialState: fun () => {
    rotation: 0,
    gameState:
      Empty |> Array.make Const.numRows |> Array.make Const.numRows |> Array.make Const.numRows
  },
  reducer: fun action state =>
    switch action {
    | Rotate inc => ReasonReact.Update {...state, rotation: state.rotation + inc}
    | Reset => ReasonReact.Update {...state, rotation: 0}
    },
  render: fun {state, reduce} =>
    <div className="Game">
      <Sidebar
        rotateClockwise=(reduce (fun _ => Rotate 90))
        rotateCounterClockwise=(reduce (fun _ => Rotate (-90)))
        reset=(reduce (fun _ => Reset))
      />
      <Board rotation=state.rotation />
    </div>
};
