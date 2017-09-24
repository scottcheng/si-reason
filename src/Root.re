let se = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent "Root";

let make _children => {
  ...component,
  render: fun _self => <div className="Root"> (se "SI") </div>
};
