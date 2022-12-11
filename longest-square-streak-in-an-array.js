/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSquareStreak = function (nums) {

  //  The length of the subsequence is at least 2, and
  // after sorting the subsequence, each element(except the first element) is the square of the previous number.
  // Return the length of the longest square streak in nums, or return -1 if there is no square streak.

  let n = nums.length;
  let subsequence = new Map();
  nums.sort((a, b) => a - b);

  let size = -1;

  for (let i = 0; i < n; i++) {
    let ans = Math.floor(Math.sqrt(nums[i]));
    if (ans * ans === nums[i] && subsequence.has(ans)) {
      subsequence.set(nums[i], subsequence.get(ans) + 1);
      if (subsequence.get(ans) + 1 > size) {
        size = subsequence.get(ans) + 1;
      }
    }
    else {
      subsequence.set(nums[i], 1);
    }
  }
  return size;
};

let nums = [10, 2, 13, 16, 8, 9, 13];
console.log(longestSquareStreak(nums));