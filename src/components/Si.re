let component = ReasonReact.statelessComponent "Si";

let make _children => {...component, render: fun _self => <div className="Si"> <Game /> </div>};
