/**
 * @param {string} s
 * @return {string}
 */
var makeGood = function (s) {
  const stack = [];
  for (let i = 0; i < s.length; i++) {
    if (stack.length && Math.abs(s[i].charCodeAt() - stack[stack.length - 1].charCodeAt()) === 32) {
      stack.pop();
    } else {
      stack.push(s[i]);
    }
  }
  return stack.join('');
};

let s = "leEeetcode";
let output = makeGood(s);
console.log(output);