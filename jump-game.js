/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function (nums) {

  let max = 0;

  for (let i = 0; i < nums.length; i++) {
    if (max < i) {
      return false;
    }
    max = Math.max(max, i + nums[i]);
  }
  return true;

};

let nums = [2, 3, 1, 1, 4];
console.log(canJump(nums));