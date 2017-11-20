let se = ReasonReact.stringToElement;

let style = ReactDOMRe.Style.make;

let component = ReasonReact.statelessComponent("Sidebar");

let make =
    (
      ~gameState: Engine.state,
      ~rotateClockwise,
      ~rotateCounterClockwise,
      ~reset,
      _children
    ) => {
  ...component,
  render: (_self) =>
    <div className="Sidebar">
      <div className="Sidebar-title"> (se("SI")) </div>
      <div className="Sidebar-section">
        (
          [(Board.P1, "Player 1"), (Board.P2, "Player 2")]
          |> List.mapi(
               (i, (player, name)) =>
                 <div
                   key=(string_of_int(i))
                   className=(
                     "Sidebar-player Sidebar-subSection"
                     ++ (
                       gameState.player == player ?
                         " Sidebar-player--active" : ""
                     )
                     ++ (
                       switch (Board.winner(gameState.board)) {
                       | Some((winner, _)) when winner == player => " Sidebar-player--winner"
                       | _ => ""
                       }
                     )
                   )>
                   <div
                     className=(
                       switch player {
                       | P1 => "Sidebar-playerBead Sidebar-playerBead--p1"
                       | P2 => "Sidebar-playerBead Sidebar-playerBead--p2"
                       }
                     )
                   />
                   (se(name))
                 </div>
             )
          |> Array.of_list
          |> ReasonReact.arrayToElement
        )
      </div>
      <div className="Sidebar-section">
        <div
          className="Sidebar-rotateBtn icon-rotate-left"
          onClick=rotateClockwise
        />
        <div
          className="Sidebar-rotateBtn icon-rotate-right"
          onClick=rotateCounterClockwise
        />
      </div>
      <div className="Sidebar-info">
        <div className="Sidebar-subSection">
          <span className="Sidebar-link" onClick=reset>
            (se("New game"))
          </span>
        </div>
        <div className="Sidebar-subSection">
          <span className="Sidebar-link"> (se("About")) </span>
        </div>
      </div>
    </div>
};
