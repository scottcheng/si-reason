let se = ReasonReact.stringToElement;

let style = ReactDOMRe.Style.make;

let component = ReasonReact.statelessComponent "Sidebar";

let make ::rotateClockwise ::rotateCounterClockwise ::reset _children => {
  ...component,
  render: fun _self =>
    <div className="Sidebar">
      <div className="Sidebar-title"> (se "SI") </div>
      <div className="Sidebar-section">
        (
          ["player 1", "player 2"] |>
          List.map (
            fun p => <div key=p className="Sidebar-player Sidebar-subSection"> (se p) </div>
          ) |> Array.of_list |> ReasonReact.arrayToElement
        )
      </div>
      <div className="Sidebar-section">
        <div className="Sidebar-rotateBtn icon-rotate-left" onClick=rotateClockwise />
        <div className="Sidebar-rotateBtn icon-rotate-right" onClick=rotateCounterClockwise />
      </div>
      <div className="Sidebar-info">
        <div className="Sidebar-subSection">
          <span className="Sidebar-link" onClick=reset> (se "New game") </span>
        </div>
        <div className="Sidebar-subSection" > <span className="Sidebar-link"> (se "About") </span></div>
      </div>
    </div>
};
