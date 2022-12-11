/**
 * @param {number[][]} grid
 * @return {number}
 */
var deleteGreatestValue = function (grid) {

  let m = 1e9 + 7, row = grid.length, col = grid[0].length, ans = 0;

  for (let i = 0; i < row; i++) {
    // sort the row 
    grid[i].sort((a, b) => a - b);
  }

  for (let i = 0; i < col; i++) {

    let max = Number.MIN_VALUE;

    for (let j = 0; j < row; j++) {
      max = Math.max(max, grid[j][i]);
    }

    ans = (ans % m + max % m) % m;

  }

  return ans;
};

let grid = [[10]];
console.log(deleteGreatestValue(grid));