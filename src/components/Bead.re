let component = ReasonReact.statelessComponent "Bead";

let cap = <div className="Bead-cap" />;

let make ::player _children => {
  ...component,
  render: fun _self =>
    switch player {
    | Board.P1 => <div className="Bead Bead--p1"> cap </div>
    | Board.P2 => <div className="Bead Bead--p2"> cap </div>
    }
};
