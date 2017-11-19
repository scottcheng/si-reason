let component = ReasonReact.statelessComponent("Si");

let make = (_children) => {
  ...component,
  render: (_self) => <div className="Si"> <Game /> </div>
};
