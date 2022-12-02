/**
 * @param {string} word1
 * @param {string} word2
 * @return {boolean}
 */
var closeStrings = function (word1, word2) {

  const m = word1.length;
  const n = word2.length;

  if (m !== n) {
    return false;
  }

  const list1 = new Array(27).fill(0)
  const list2 = new Array(27).fill(0)

  for (let i = 0; i < m; i++) {
    list1[word1.charCodeAt(i) - 97]++
    list2[word2.charCodeAt(i) - 97]++
  }

  for (let i = 0; i < 27; i++) {
    if (list1[i] > 0 && list2[i] > 0) {
      continue;
    }
    if (list1[i] === 0 && list2[i] === 0) {
      continue;
    }
    return false;
  }

  // Sorting
  list1.sort()
  list2.sort()

  //should have same frequency
  for (let i = 0; i < 27; i++) {
    if (list1[i] !== list2[i]) {
      return false;
    }
  }

  return true;
};

let word1 = "abc", word2 = "bca";
console.log(closeStrings(word1, word2));