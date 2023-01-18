/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubarraySumCircular = function (nums) {

  let maxSum = -Infinity;
  let minSum = Infinity;
  let sum = 0;
  let maxSumSoFar = 0;
  let minSumSoFar = 0;

  for (let i = 0; i < nums.length; i++) {
    sum += nums[i];
    maxSumSoFar = Math.max(maxSumSoFar + nums[i], nums[i]);
    maxSum = Math.max(maxSum, maxSumSoFar);
    minSumSoFar = Math.min(minSumSoFar + nums[i], nums[i]);
    minSum = Math.min(minSum, minSumSoFar);
  }

  if (maxSum < 0) {
    return maxSum;
  }

  return Math.max(maxSum, sum - minSum);

};

let nums = [1, -2, 3, -2];
let result = maxSubarraySumCircular(nums);
console.log(result);