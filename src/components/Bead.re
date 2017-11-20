let component = ReasonReact.statelessComponent("Bead");

let cap = <div className="Bead-cap" />;

let make = (~player, ~winning, _children) => {
  ...component,
  render: (_self) =>
    switch player {
    | Board.P1 =>
      <div
        className=(
          Util.cx([
            ("Bead", true),
            ("Bead--p1", true),
            ("Bead--winning", winning)
          ])
        )>
        cap
      </div>
    | Board.P2 =>
      <div
        className=(
          Util.cx([
            ("Bead", true),
            ("Bead--p2", true),
            ("Bead--winning", winning)
          ])
        )>
        cap
      </div>
    }
};
