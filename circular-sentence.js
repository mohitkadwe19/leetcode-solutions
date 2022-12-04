/**
 * @param {string} sentence
 * @return {boolean}
 */
var isCircularSentence = function (sentence) {

  let arr = sentence.split(" ");

  let len = arr.length;

  for (let i = 0; i < len - 1; i++) {

    if (arr[i].charAt(arr[i].length - 1) != arr[i + 1].charAt(0)) {
      return false;
    }
  }

  if (arr[len - 1].charAt(arr[len - 1].length - 1) != arr[0].charAt(0)) {
    return false;
  }

  return true;

};
let sentence = "leetcode exercises sound delightful";
console.log(isCircularSentence(sentence));