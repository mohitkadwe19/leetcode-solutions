/**
 * @param {number[][]} grid
 * @return {number}
 */
var uniquePathsIII = function (grid) {

  let count = 0;
  let start = [];
  let end = [];
  let empty = 1;

  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[0].length; j++) {
      if (grid[i][j] === 1) {
        start = [i, j];
      } else if (grid[i][j] === 2) {
        end = [i, j];
      } else if (grid[i][j] === 0) {
        empty++;
      }
    }
  }

  let dfs = (i, j, empty) => {
    if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] === -1) {
      return;
    }
    if (i === end[0] && j === end[1]) {
      if (empty === 0) {
        count++;
      }
      return;
    }
    grid[i][j] = -1;
    dfs(i + 1, j, empty - 1);
    dfs(i - 1, j, empty - 1);
    dfs(i, j + 1, empty - 1);
    dfs(i, j - 1, empty - 1);
    grid[i][j] = 0;
  };

  dfs(start[0], start[1], empty);
  return count;

};

let grid = [[1, 0, 0, 0], [0, 0, 0, 0], [0, 0, 2, -1]];
console.log(uniquePathsIII(grid));