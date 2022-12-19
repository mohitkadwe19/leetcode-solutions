/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} source
 * @param {number} destination
 * @return {boolean}
 */
var validPath = function (n, edges, source, destination) {

  let graph = new Map();
  let visited = new Set();

  for (let [u, v] of edges) {
    if (!graph.has(u)) {
      graph.set(u, []);
    }
    if (!graph.has(v)) {
      graph.set(v, []);
    }
    graph.get(u).push(v);
    graph.get(v).push(u);
  }

  let queue = [source];

  while (queue.length > 0) {
    let node = queue.shift();
    if (node === destination) {
      return true;
    }
    if (visited.has(node)) {
      continue;
    }
    visited.add(node);
    if (graph.has(node)) {
      for (let neighbor of graph.get(node)) {
        if (!visited.has(neighbor)) {
          queue.push(neighbor);
        }
      }
    }
  }

  return false;

};

let n = 3, edges = [[0, 1], [1, 2], [2, 0]], source = 0, destination = 2;

console.log(validPath(n, edges, source, destination));