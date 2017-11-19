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
  initialState: fun () => {rotation: 0, gameState: Engine.initialState},
  reducer: fun action state =>
    switch action {
    | Rotate inc => ReasonReact.Update {...state, rotation: state.rotation + inc}
    | Reset => ReasonReact.Update {rotation: 0, gameState: Engine.initialState}
    | Move (x, y) => ReasonReact.Update {...state, gameState: Engine.move (x, y) state.gameState}
    },
  render: fun {state, reduce} =>
    <div className="Game">
      <Sidebar
        rotateClockwise=(reduce (fun _ => Rotate (-90)))
        rotateCounterClockwise=(reduce (fun _ => Rotate 90))
        reset=(reduce (fun _ => Reset))
      />
      <BoardView
        rotation=state.rotation
        board=state.gameState.board
        move=(reduce (fun (x, y) => Move (x, y)))
      />
      (
        ReasonReact.stringToElement (
          switch (Board.winner state.gameState.board) {
          | Some P1 => "winner is P1"
          | Some P2 => "winner is P2"
          | _ => "no winner"
          }
        )
      )
    </div>
};
