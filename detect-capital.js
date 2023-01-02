/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function (word) {

  // All letters in this word are capitals, like "USA".
  if (word.toUpperCase() === word) {
    return true;
  }

  // All letters in this word are not capitals, like "leetcode".
  if (word.toLowerCase() === word) {
    return true;
  }

  // Only the first letter in this word is capital if it has more than one letter, like "Google".
  if (word[0].toUpperCase() === word[0] && word.substring(1).toLowerCase() === word.substring(1)) {
    return true;
  }

  return false;

};

let word = "FlaG";
let result = detectCapitalUse(word);
console.log(result);