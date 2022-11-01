/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var findBall = function (grid) {
  const m = grid.length;
  const n = grid[0].length;
  const result = [];
  for (let i = 0; i < n; i++) {
    let x = 0;
    let y = i;
    while (x < m) {
      if (grid[x][y] === 1) {
        if (y === n - 1 || grid[x][y + 1] === -1) {
          result.push(-1);
          break;
        }
        y++;
      } else {
        if (y === 0 || grid[x][y - 1] === 1) {
          result.push(-1);
          break;
        }
        y--;
      }
      x++;
    }
    if (x === m) {
      result.push(y);
    }
  }
  return result;
};

let grid = [[1, 1, 1, -1, -1], [1, 1, 1, -1, -1], [-1, -1, -1, 1, 1], [1, 1, 1, 1, -1], [-1, -1, -1, -1, -1]];
console.log(findBall(grid));