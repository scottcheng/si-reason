type state = {
  rotation: int, /* In degrees */
  gameState: Engine.state,
  showAbout: bool
};

type actions =
  | Rotate(int)
  | Move((int, int))
  | Reset
  | OpenAbout
  | CloseAbout;

let component = ReasonReact.reducerComponent("Game");

let make = (_children) => {
  ...component,
  initialState: () => {
    rotation: 0,
    gameState: Engine.initialState,
    showAbout: false
  },
  reducer: (action, state) =>
    switch action {
    | Rotate(inc) =>
      ReasonReact.Update({...state, rotation: state.rotation + inc})
    | Move((x, y)) =>
      ReasonReact.Update({
        ...state,
        gameState: Engine.move((x, y), state.gameState)
      })
    | Reset =>
      ReasonReact.Update({
        rotation: 0,
        gameState: Engine.initialState,
        showAbout: false
      })
    | OpenAbout => ReasonReact.Update({...state, showAbout: true})
    | CloseAbout => ReasonReact.Update({...state, showAbout: false})
    },
  render: ({state: {rotation, gameState, showAbout}, reduce}) =>
    <div className="Game">
      <Sidebar
        gameState
        rotateClockwise=(reduce((_) => Rotate((-90))))
        rotateCounterClockwise=(reduce((_) => Rotate(90)))
        reset=(reduce((_) => Reset))
        openAbout=(reduce((_) => OpenAbout))
      />
      <BoardView
        rotation
        board=gameState.board
        move=(reduce(((x, y)) => Move((x, y))))
      />
      (
        showAbout ?
          <About close=(reduce((_) => CloseAbout)) /> : ReasonReact.nullElement
      )
    </div>
};
