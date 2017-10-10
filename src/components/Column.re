let se = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent "Column";

let make ::i ::j _children => {
  ...component,
  render: fun _self =>
    <div className="Column"> (se (string_of_int i ^ "-" ^ string_of_int j)) </div>
};
