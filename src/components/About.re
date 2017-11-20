let se = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("About");

let make = (~close, _children) => {
  ...component,
  render: (_self) =>
    <div className="About" onClick=close>
      <div
        className="About-content" onClick=ReactEventRe.Mouse.stopPropagation>
        <p>
          (se("Si is an online version of "))
          <a target="_blank" href="https://en.wikipedia.org/wiki/Score_Four">
            (se("Score Four"))
          </a>
          (se(", or 3D "))
          <a target="_blank" href="https://en.wikipedia.org/wiki/Connect_Four">
            (se("Connect Four"))
          </a>
          (se(". "))
          (se({js|The name, Si, means four in Chinese — 四 / 肆.|js}))
        </p>
        <p>
          (
            se(
              "The rule is simple: two players take turns to put pieces on "
              ++ "one of the 16 columns, with the objective of connecting 4 "
              ++ "of your pieces in a straight line in any direction."
            )
          )
        </p>
        <p>
          (
            se(
              "In its current form, two players play on the same computer. "
              ++ "Future versions may introduce remote games, and AI players."
            )
          )
        </p>
        <p>
          <i>
            (se("Made by "))
            <a target="_blank" href="http://scottcheng.com">
              (se("Scott Cheng"))
            </a>
            (se(". "))
            (se("Written in "))
            <a target="_blank" href="https://reasonml.github.io/">
              (se("Reason"))
            </a>
            (se(" and open sourced on "))
            <a target="_blank" href="https://github.com/scottcheng/si-reason">
              (se("GitHub"))
            </a>
            (se("."))
          </i>
        </p>
      </div>
    </div>
};
