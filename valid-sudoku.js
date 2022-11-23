/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function (board) {

  let row = new Array(9).fill(0);
  let col = new Array(9).fill(0);
  let box = new Array(9).fill(0);

  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      if (board[i][j] !== '.') {
        let num = board[i][j];
        let k = Math.floor(i / 3) * 3 + Math.floor(j / 3);
        if (row[i] & (1 << num) || col[j] & (1 << num) || box[k] & (1 << num)) {
          return false;
        }
        row[i] |= (1 << num);
        col[j] |= (1 << num);
        box[k] |= (1 << num);
      }
    }
  }
  return true;

};

let board =
  [["5", "3", ".", ".", "7", ".", ".", ".", "."]
    , ["6", ".", ".", "1", "9", "5", ".", ".", "."]
    , [".", "9", "8", ".", ".", ".", ".", "6", "."]
    , ["8", ".", ".", ".", "6", ".", ".", ".", "3"]
    , ["4", ".", ".", "8", ".", "3", ".", ".", "1"]
    , ["7", ".", ".", ".", "2", ".", ".", ".", "6"]
    , [".", "6", ".", ".", ".", ".", "2", "8", "."]
    , [".", ".", ".", "4", "1", "9", ".", ".", "5"]
    , [".", ".", ".", ".", "8", ".", ".", "7", "9"]];
console.log(isValidSudoku(board));