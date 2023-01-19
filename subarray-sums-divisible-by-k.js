/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraysDivByK = function (nums, k) {

  let map = new Map();
  map.set(0, 1);

  let sum = 0;
  let count = 0;
  for (let i = 0; i < nums.length; i++) {
    sum += nums[i];
    let mod = (sum % k + k) % k;
    let same = map.get(mod) || 0;
    count += same;
    map.set(mod, same + 1);
  }
  return count;

};

let nums = [4, 5, 0, -2, -3, 1], k = 5;
console.log(subarraysDivByK(nums, k));