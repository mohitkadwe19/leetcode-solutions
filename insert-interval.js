/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function (intervals, newInterval) {

  let result = [];
  let i = 0;
  let len = intervals.length;

  // add all intervals ending before newInterval starts
  while (i < len && intervals[i][1] < newInterval[0]) {
    result.push(intervals[i]);
    i++;
  }

  // merge all intervals that overlap with newInterval
  while (i < len && intervals[i][0] <= newInterval[1]) {
    newInterval[0] = Math.min(intervals[i][0], newInterval[0]);
    newInterval[1] = Math.max(intervals[i][1], newInterval[1]);
    i++;
  }

  // add the union of intervals we got
  result.push(newInterval);

  // add all the rest
  while (i < len) {
    result.push(intervals[i]);
    i++;
  }

  return result;

};

let intervals = [[1, 3], [6, 9]], newInterval = [2, 5];
console.log(insert(intervals, newInterval));