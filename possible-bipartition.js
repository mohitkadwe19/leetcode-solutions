/**
 * @param {number} n
 * @param {number[][]} dislikes
 * @return {boolean}
 */
var possibleBipartition = function (n, dislikes) {

  let graph = new Map();
  for (let i = 1; i <= n; i++) {
    graph.set(i, []);
  }
  for (let dislike of dislikes) {
    graph.get(dislike[0]).push(dislike[1]);
    graph.get(dislike[1]).push(dislike[0]);
  }

  let colors = new Map();
  for (let i = 1; i <= n; i++) {
    colors.set(i, 0);
  }

  for (let i = 1; i <= n; i++) {
    if (colors.get(i) === 0 && !dfs(i, 1)) {
      return false;
    }
  }

  function dfs(node, color) {
    if (colors.get(node) !== 0) {
      return colors.get(node) === color;
    }
    colors.set(node, color);
    for (let neighbor of graph.get(node)) {
      if (!dfs(neighbor, -color)) {
        return false;
      }
    }
    return true;
  }

  return true;


};

let n = 4, dislikes = [[1, 2], [1, 3], [2, 4]];
console.log(possibleBipartition(n, dislikes));