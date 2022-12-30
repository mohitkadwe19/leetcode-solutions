/**
 * @param {number[][]} graph
 * @return {number[][]}
 */
var allPathsSourceTarget = function (graph) {

  let paths = [];
  let path = [0];

  let dfs = (node) => {
    if (node === graph.length - 1) {
      paths.push(path.slice());
      return;
    }

    for (let next of graph[node]) {
      path.push(next);
      dfs(next);
      path.pop();
    }
  };

  dfs(0);
  return paths;

};

let graph = [[1, 2], [3], [3], []];
console.log(allPathsSourceTarget(graph));