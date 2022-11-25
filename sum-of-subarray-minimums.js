/**
 * @param {number[]} arr
 * @return {number}
 */
var sumSubarrayMins = function (arr) {

  let sum = 0;
  let mod = 1e9 + 7;
  let stack = [];

  for (let i = 0; i < arr.length; i++) {
    while (stack.length && arr[stack[stack.length - 1]] > arr[i]) {
      let index = stack.pop();
      let left = stack.length ? stack[stack.length - 1] : -1;
      sum += arr[index] * (i - index) * (index - left);
      sum %= mod;
    }
    stack.push(i);
  }

  while (stack.length) {
    let index = stack.pop();
    let left = stack.length ? stack[stack.length - 1] : -1;
    sum += arr[index] * (arr.length - index) * (index - left);
    sum %= mod;
  }

  return sum;

};

let arr = [3, 1, 2, 4];
console.log(sumSubarrayMins(arr));