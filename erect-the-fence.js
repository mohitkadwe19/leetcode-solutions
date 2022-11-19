/**
 * @param {number[][]} trees
 * @return {number[][]}
 */
var outerTrees = function (trees) {

  function cmp(p1, p2, p3) {
    let [x1, y1] = p1;
    let [x2, y2] = p2;
    let [x3, y3] = p3;
    return (y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2);
  }

  trees.sort((a, b) => {
    let diff = a[0] - b[0];
    if (diff === 0) return a[1] - b[1];
    return diff
  });

  const upper = [];
  const lower = [];

  for (let point of trees) {
    while (lower.length > 1 && cmp(lower[lower.length - 2], lower[lower.length - 1], point) > 0) {
      lower.pop()
    }
    while (upper.length > 1 && cmp(upper[upper.length - 2], upper[upper.length - 1], point) < 0) {
      upper.pop()
    }
    upper.push(point);
    lower.push(point);
  }

  return Array.from(new Set(upper.concat(lower)))

};
let points = [[1, 1], [2, 2], [2, 0], [2, 4], [3, 3], [4, 2]];
console.log(outerTrees(points));