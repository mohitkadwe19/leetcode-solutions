/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {string} labels
 * @return {number[]}
 */
var countSubTrees = function (n, edges, labels) {

  let graph = new Array(n).fill(0).map(() => new Array());
  for (let [u, v] of edges) {
    graph[u].push(v);
    graph[v].push(u);
  }

  let ans = new Array(n).fill(0);
  let dfs = (node, parent) => {
    let freq = new Array(26).fill(0);
    for (let child of graph[node]) {
      if (child == parent) continue;
      let childFreq = dfs(child, node);
      for (let i = 0; i < 26; i++) {
        freq[i] += childFreq[i];
      }
    }
    freq[labels.charCodeAt(node) - 97]++;
    ans[node] = freq[labels.charCodeAt(node) - 97];
    return freq;
  }
  dfs(0, -1);
  return ans;

};

let n = 7, edges = [[0, 1], [0, 2], [1, 4], [1, 5], [2, 3], [2, 6]], labels = "abaedcd";
console.log(countSubTrees(n, edges, labels));