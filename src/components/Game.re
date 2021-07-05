type state = {
  rotation: int, /* In degrees */
  gameState: Engine.state,
  showAbout: bool,
};

type actions =
  | Rotate(int)
  | Move((int, int))
  | Reset
  | OpenAbout
  | CloseAbout;

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | Rotate(inc) => {...state, rotation: state.rotation + inc}
        | Move((x, y)) => {
            ...state,
            gameState: Engine.move((x, y), state.gameState),
          }
        | Reset => {
            rotation: 0,
            gameState: Engine.initialState,
            showAbout: false,
          }
        | OpenAbout => {...state, showAbout: true}
        | CloseAbout => {...state, showAbout: false}
        },
      {rotation: 0, gameState: Engine.initialState, showAbout: false},
    );

  let {rotation, gameState, showAbout} = state;
  <div className="Game">
    <Sidebar
      gameState
      rotateClockwise={_e =>dispatch(Rotate(-90))}
      rotateCounterClockwise={_e =>dispatch(Rotate(90))}
      reset={_e =>dispatch(Reset)}
      openAbout={_e =>dispatch(OpenAbout)}
    />
    <BoardView
      rotation
      board={gameState.board}
      move={((x, y)) => dispatch(Move((x, y)))}
    />
    {showAbout ? <About close={_e =>dispatch(CloseAbout)} /> : React.null}
  </div>;
};
