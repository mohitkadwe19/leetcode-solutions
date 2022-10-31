/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
var isToeplitzMatrix = function (matrix) {
  const m = matrix.length;
  const n = matrix[0].length;
  for (let i = 0; i < m - 1; i++) {
    for (let j = 0; j < n - 1; j++) {
      if (matrix[i][j] !== matrix[i + 1][j + 1]) {
        return false;
      }
    }
  }
  return true;
};

let matrix = [[1, 2, 3, 4], [5, 1, 2, 3], [9, 5, 1, 2]];
console.log(isToeplitzMatrix(matrix));