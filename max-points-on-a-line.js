/**
 * @param {number[][]} points
 * @return {number}
 */

var getGcd = function (a, b) {
  if (b === 0) {
    return a;
  }
  return getGcd(b, a % b);
}

var maxPoints = function (points) {

  if (points.length === 0) {
    return 0;
  }

  let max = 1;
  for (let i = 0; i < points.length; i++) {
    let map = new Map();
    let same = 0;
    for (let j = i + 1; j < points.length; j++) {
      let x = points[j][0] - points[i][0];
      let y = points[j][1] - points[i][1];
      if (x === 0 && y === 0) {
        same++;
        continue;
      }
      let gcd = getGcd(x, y);
      x /= gcd;
      y /= gcd;
      let key = x + "," + y;
      if (map.has(key)) {
        map.set(key, map.get(key) + 1);
      } else {
        map.set(key, 2);
      }
      max = Math.max(max, map.get(key) + same);
    }
  }
  return max;

};

let points = [[1, 1], [2, 2], [3, 3]];
console.log(maxPoints(points));