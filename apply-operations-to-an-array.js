/**
 * @param {number[]} nums
 * @return {number[]}
 */
var applyOperations = function (nums) {

  //   You are given a 0 - indexed array nums of size n consisting of non - negative integers.

  // You need to apply n - 1 operations to this array where, in the ith operation(0 - indexed), you will apply the following on the ith element of nums:

  // If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to 0. Otherwise, you skip this operation.
  // After performing all the operations, shift all the 0's to the end of the array.

  // For example, the array[1, 0, 2, 0, 0, 1] after shifting all its 0's to the end, is [1,2,1,0,0,0].
  // Return the resulting array.

  let result = [];

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === nums[i + 1]) {
      nums[i] = nums[i] << 1;
      nums[i + 1] = 0;
    }
  }

  let countZero = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === 0) {
      countZero++;
    }
    else {
      result.push(nums[i]);
    }
  }

  while (countZero--) {
    result.push(0);
  }

  return result;
};

let nums = [1, 2, 2, 1, 1, 0];
let result = applyOperations(nums);
console.log(result);