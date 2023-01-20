/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var findSubsequences = function (nums) {

  let result = [];

  function dfs(nums, start, path) {
    if (path.length >= 2) {
      result.push(path.slice());
    }
    let used = {};
    for (let i = start; i < nums.length; i++) {
      if ((path.length === 0 || nums[i] >= path[path.length - 1]) && !used[nums[i]]) {
        used[nums[i]] = true;
        path.push(nums[i]);
        dfs(nums, i + 1, path);
        path.pop();
      }
    }
  }

  dfs(nums, 0, []);
  return result;
};

let nums = [4, 6, 7, 7];
console.log(findSubsequences(nums));