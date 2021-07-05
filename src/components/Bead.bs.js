// Generated by ReScript, PLEASE EDIT WITH CARE

import * as React from "react";
import * as Util$SiReason from "../util.bs.js";

var cap = React.createElement("div", {
      className: "Bead-cap"
    });

function Bead(Props) {
  var player = Props.player;
  var winning = Props.winning;
  if (player) {
    return React.createElement("div", {
                className: Util$SiReason.cx({
                      hd: [
                        "Bead",
                        true
                      ],
                      tl: {
                        hd: [
                          "Bead--p2",
                          true
                        ],
                        tl: {
                          hd: [
                            "Bead--winning",
                            winning
                          ],
                          tl: /* [] */0
                        }
                      }
                    })
              }, cap);
  } else {
    return React.createElement("div", {
                className: Util$SiReason.cx({
                      hd: [
                        "Bead",
                        true
                      ],
                      tl: {
                        hd: [
                          "Bead--p1",
                          true
                        ],
                        tl: {
                          hd: [
                            "Bead--winning",
                            winning
                          ],
                          tl: /* [] */0
                        }
                      }
                    })
              }, cap);
  }
}

var make = Bead;

export {
  cap ,
  make ,
  
}
/* cap Not a pure module */