let cap = <div className="Bead-cap" />;
[@react.component]
let make = (~player, ~winning) => {
  switch (player) {
  | Board.P1 =>
    <div
      className={Util.cx([
        ("Bead", true),
        ("Bead--p1", true),
        ("Bead--winning", winning),
      ])}>
      cap
    </div>
  | Board.P2 =>
    <div
      className={Util.cx([
        ("Bead", true),
        ("Bead--p2", true),
        ("Bead--winning", winning),
      ])}>
      cap
    </div>
  };
};
