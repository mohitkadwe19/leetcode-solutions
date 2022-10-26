/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */

const checkSubarraySum = function (nums, k) {

  let unorderedMap = new Map();
  unorderedMap.set(0, -1);
  let sum = 0;

  for (let i = 0; i < nums.length; i++) {

    sum += nums[i];

    if (k !== 0) {
      sum = sum % k;
    }

    if (unorderedMap.has(sum)) {
      if (i - unorderedMap.get(sum) > 1) {
        return true;
      }
    } else {
      unorderedMap.set(sum, i);
    }
  }
  return false;
};

console.log(checkSubarraySum([23, 2, 4, 6, 7], 6));