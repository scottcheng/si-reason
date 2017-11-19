type state = {
  board: Board.state,
  player: Board.player
};

/* TODO: Randomize player */
let initialState = {board: Board.emptyState, player: Board.P1};

let otherPlayer = (player) =>
  switch player {
  | Board.P1 => Board.P2
  | Board.P2 => Board.P1
  };

let move = ((x, y), {board, player}) =>
  Board.isValidMove((x, y), board) ?
    {board: Board.move((x, y), player, board), player: otherPlayer(player)} : {board, player};
