%raw{|import './main.scss'|};
%raw{|import './assets/fonts/icons.woff'|}

switch(ReactDOM.querySelector("#root")){
  | Some(root) => ReactDOM.render(<Si />, root)
  | None => Js.log("Coudn't find #root element to mount the React app.")
}
