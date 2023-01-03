/**
 * @param {string[]} strs
 * @return {number}
 */
var minDeletionSize = function (strs) {

  let count = 0;
  let len = strs[0].length;
  for (let i = 0; i < len; i++) {
    for (let j = 0; j < strs.length - 1; j++) {
      if (strs[j].charCodeAt(i) > strs[j + 1].charCodeAt(i)) {
        count++;
        break;
      }
    }
  }
  return count;

};

let strs = ["cba", "daf", "ghi"];
console.log(minDeletionSize(strs));