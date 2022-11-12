/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {

  let i = 0;
  let j = 1;

  while (j < nums.length) {
    if (nums[i] !== nums[j]) {
      i++;
      nums[i] = nums[j];
    }
    j++;
  }

  console.log(nums);

  return i + 1;

};
let nums = [1, 1, 2];
console.log(removeDuplicates(nums));