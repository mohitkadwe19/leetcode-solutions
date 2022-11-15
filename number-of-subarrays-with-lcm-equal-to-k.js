function gcd(a, b) {
  return !b ? a : gcd(b, a % b);
}

function lcm(a, b) {
  return (a * b) / gcd(a, b);
}

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

var subarrayLCM = function (nums, k) {

  let ans = 0;
  for (let i = 0; i < nums.length; i++) {

    let temp = nums[i];

    for (let j = i; j < nums.length; j++) {

      temp = lcm(nums[j], temp);
      if (temp == k) { ans++; }

    }
  }
  return ans;

};


let nums = [3, 6, 2, 7, 1], k = 6;
console.log(subarrayLCM(nums, k));