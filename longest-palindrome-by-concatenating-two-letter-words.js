/**
 * @param {string[]} words
 * @return {number}
 */
var longestPalindrome = function (words) {
  let length = 0;
  let map = new Map();
  for (let i = 0; i < words.length; ++i) {
    let key = words[i][1] + words[i][0];
    if (map.has(key)) {
      if (map.get(key) === 1) {
        map.delete(key);
      } else {
        map.set(key, map.get(key) - 1);
      }
      length += 4;
    }
    else {
      if (map.has(words[i])) {
        map.set(words[i], map.get(words[i]) + 1);
      } else {
        map.set(words[i], 1);
      }
    }
  }

  for (let word of map.keys()) {
    if (word[0] === word[1]) {
      length += 2;
      break;
    }
  }

  return length;
};

let words = ["lc", "cl", "gg"];
console.log(longestPalindrome(words));