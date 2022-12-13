/**
 * @param {number[][]} matrix
 * @return {number}
 */
var minFallingPathSum = function (matrix) {

  let dp = new Array(matrix.length).fill(0).map(() => new Array(matrix.length).fill(0));
  for (let i = 0; i < matrix.length; i++) {
    dp[0][i] = matrix[0][i];
  }

  for (let i = 1; i < matrix.length; i++) {
    for (let j = 0; j < matrix.length; j++) {
      dp[i][j] = matrix[i][j] + Math.min(dp[i - 1][j], dp[i - 1][j - 1] || Infinity, dp[i - 1][j + 1] || Infinity);
      console.log(dp[i][j]);
    }
  }

  return Math.min(...dp[matrix.length - 1]);
};

let matrix = [[2, 1, 3], [6, 5, 4], [7, 8, 9]];
console.log(minFallingPathSum(matrix));