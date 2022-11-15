/**
 * @param {number[][]} stones
 * @return {number}
 */
var removeStones = function (stones) {

  const n = stones.length;
  const parent = new Array(n).fill(0).map((e, i) => i);
  const rank = new Array(n).fill(0);

  const find = (x) => {
    if (parent[x] !== x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  };

  const union = (x, y) => {
    let rootX = find(x);
    let rootY = find(y);
    if (rootX === rootY) {
      return false;
    }
    if (rank[rootX] < rank[rootY]) {
      [rootX, rootY] = [rootY, rootX];
    }
    parent[rootY] = rootX;
    rank[rootX] += rank[rootX] === rank[rootY] ? 1 : 0;
    return true;
  };

  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      if (stones[i][0] === stones[j][0] || stones[i][1] === stones[j][1]) {
        union(i, j);
      }
    }
  }

  const set = new Set();
  for (let i = 0; i < n; i++) {
    set.add(find(i));
  }
  return n - set.size;

};

let stones = [[0, 0], [0, 1], [1, 0], [1, 2], [2, 1], [2, 2]];
console.log(removeStones(stones));