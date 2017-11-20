let component = ReasonReact.statelessComponent("Bead");

let cap = <div className="Bead-cap" />;

let make = (~player, ~winning, _children) => {
  ...component,
  render: (_self) =>
    switch player {
    | Board.P1 =>
      <div className=("Bead Bead--p1" ++ (winning ? " Bead--winning" : ""))>
        cap
      </div>
    | Board.P2 =>
      <div className=("Bead Bead--p2" ++ (winning ? " Bead--winning" : ""))>
        cap
      </div>
    }
};
