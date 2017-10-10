type state = {
  rotation: int, /* In degrees */
  gameState: Engine.state
};

type actions =
  | Rotate int
  | Reset
  | Move (int, int);

let component = ReasonReact.reducerComponent "Game";

let make _children => {
  ...component,
  initialState: fun () => {rotation: 0, gameState: Engine.emptyState},
  reducer: fun action state =>
    switch action {
    | Rotate inc => ReasonReact.Update {...state, rotation: state.rotation + inc}
    | Reset => ReasonReact.Update {...state, rotation: 0}
    | Move (i, j) =>
      /* TODO: pass in active player */
      ReasonReact.Update {...state, gameState: Engine.move (i, j) P1 state.gameState}
    },
  render: fun {state, reduce} =>
    <div className="Game">
      <Sidebar
        rotateClockwise=(reduce (fun _ => Rotate (-90)))
        rotateCounterClockwise=(reduce (fun _ => Rotate 90))
        reset=(reduce (fun _ => Reset))
      />
      <Board
        rotation=state.rotation
        gameState=state.gameState
        move=(reduce (fun (i, j) => Move (i, j)))
      />
    </div>
};
