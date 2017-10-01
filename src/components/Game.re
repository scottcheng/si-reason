let se = ReasonReact.stringToElement;

/* TODO: Write game state and move to a separate file */
type gameState = string;

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
  initialState: fun () => {rotation: 0, gameState: ""},
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
