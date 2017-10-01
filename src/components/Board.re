let se = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent "Board";

let make ::rotation _children => {
  ...component,
  render: fun _self => <div className="Board"> (se ("Board" ^ " " ^ string_of_int rotation)) </div>
};
