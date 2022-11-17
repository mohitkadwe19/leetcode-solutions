/**
 * @param {number} ax1
 * @param {number} ay1
 * @param {number} ax2
 * @param {number} ay2
 * @param {number} bx1
 * @param {number} by1
 * @param {number} bx2
 * @param {number} by2
 * @return {number}
 */
var computeArea = function (ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) {


  let area1 = (ax2 - ax1) * (ay2 - ay1)
  let area2 = (bx2 - bx1) * (by2 - by1)
  let overlap = (by1 > ay2 || by2 < ay1 || bx1 > ax2 || bx2 < ax1) ? 0 : Math.abs((Math.min(ax2, bx2) - Math.max(ax1, bx1)) * (Math.min(ay2, by2) - Math.max(ay1, by1)))

  return area1 + area2 - overlap;

};

let ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
console.log(computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2));