let component = ReasonReact.statelessComponent "Bead";

let make ::el _children => {
  ...component,
  render: fun _self =>
    switch el {
    | Engine.Empty => ReasonReact.nullElement
    | Engine.P1 => <div className="Bead Bead-p1" />
    | Engine.P2 => <div className="Bead Bead-p2" />
    }
};
