// Generated by ReScript, PLEASE EDIT WITH CARE

import * as List from "bs-platform/lib/es6/list.js";

function cx(classNames) {
  return List.fold_left((function (curClass, param) {
                if (param[1]) {
                  return "" + curClass + " " + param[0];
                } else {
                  return curClass;
                }
              }), "", classNames);
}

export {
  cx ,
  
}
/* No side effect */