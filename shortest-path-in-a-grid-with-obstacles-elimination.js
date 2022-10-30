/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var shortestPath = function (grid, k) {

  let m = grid.length
  let n = m && grid[0].length

  if (m === 1 && n === 1) {
    return 0;
  }

  let queue = [[0, 0, k]]
  let dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]
  let visited = new Set()
  let steps = 0

  while (queue.length > 0) {

    let size = queue.length

    while (size--) {

      let [row, col, em] = queue.shift()

      if (visited.has(row + '#' + col + '#' + em)) {
        continue
      }
      visited.add(row + '#' + col + '#' + em)
      for (let dir of dirs) {
        let nx = row + dir[0]
        let ny = col + dir[1]
        if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited.has(nx + '#' + ny + '#' + em)) {
          continue;
        }
        if (nx === m - 1 && ny === n - 1) {
          return steps + 1;
        }
        if (grid[nx][ny] === 1) {
          if (em > 0) {
            queue.push([nx, ny, em - 1]);
          }
        } else {
          queue.push([nx, ny, em]);
        }
      }
    }
    steps++
  }
  return -1

};

let grid = [[0, 0, 0], [1, 1, 0], [0, 0, 0], [0, 1, 1], [0, 0, 0]], k = 1;
let result = shortestPath(grid, k);
console.log(result);