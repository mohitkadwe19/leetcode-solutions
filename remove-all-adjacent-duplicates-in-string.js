/**
 * @param {string} s
 * @return {string}
 */
var removeDuplicates = function (s) {

  let stack = [];
  for (let i = 0; i < s.length; i++) {
    if (stack.length && stack[stack.length - 1] === s[i]) {
      stack.pop();
    } else {
      stack.push(s[i]);
    }
  }
  return stack.join('');

};

let s = "abbaca";
let result = removeDuplicates(s);
console.log(result);