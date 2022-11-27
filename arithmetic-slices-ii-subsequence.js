/**
 * @param {number[]} nums
 * @return {number}
 */
var numberOfArithmeticSlices = function (nums) {

  let count = 0;
  let dp = [];
  for (let i = 0; i < nums.length; i++) {
    dp[i] = {};
    for (let j = 0; j < i; j++) {
      let diff = nums[i] - nums[j];
      dp[i][diff] = (dp[i][diff] || 0) + 1;
      if (dp[j][diff]) {
        dp[i][diff] += dp[j][diff];
        count += dp[j][diff];
      }
    }
  }
  return count;

};

let nums = [2, 4, 6, 8, 10];
let result = numberOfArithmeticSlices(nums);
console.log(result);