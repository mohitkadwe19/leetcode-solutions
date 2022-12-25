/**
 * @param {string[]} words
 * @param {string} target
 * @param {number} startIndex
 * @return {number}
 */
var closetTarget = function (words, target, startIndex) {

  let targetIndex = words.indexOf(target);
  if (targetIndex === -1) {
    return -1;
  }

  let distance = Math.abs(targetIndex - startIndex);
  let length = words.length;
  let minDistance = Math.min(distance, length - distance);

  for (let i = 0; i < length; i++) {
    if (words[i] === target) {
      distance = Math.abs(i - startIndex);
      minDistance = Math.min(minDistance, distance, length - distance);
    }
  }

  return minDistance;

};

let words = ["hello", "i", "am", "leetcode", "hello"], target = "hello", startIndex = 1

console.log(closetTarget(words, target, startIndex));