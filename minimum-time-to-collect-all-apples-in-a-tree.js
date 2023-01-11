/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {boolean[]} hasApple
 * @return {number}
 */
var minTime = function (n, edges, hasApple) {

  const parentMap = new Map();
  let answer = 0;
  for (let i = 0; i < edges.length; i++) {
    parentMap.set(edges[i][1], edges[i][0]);
  }
  for (let i = 0; i < hasApple.length; i++) {
    if (hasApple[i]) {
      let pointer = i;
      while (pointer !== 0) {
        const parent = parentMap.get(pointer);
        answer += 2;
        if (hasApple[parent]) {
          break;
        }
        hasApple[parent] = true;
        pointer = parent;
      }
    }
  }
  return answer;
};

let n = 7, edges = [[0, 1], [0, 2], [1, 4], [1, 5], [2, 3], [2, 6]], hasApple = [false, false, true, false, true, true, false];
console.log(minTime(n, edges, hasApple));
