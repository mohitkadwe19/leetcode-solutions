/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function (s) {

  let mp = new Map();
  for (let i = 0; i < s.length; i++) {
    if (mp.has(s[i])) {
      mp.set(s[i], mp.get(s[i]) + 1);
    } else {
      mp.set(s[i], 1);
    }
  }

  let sortedString = Array.from(mp).sort((a, b) => b[1] - a[1]).map(v => v[0]);

  let result = "";
  for (let item of sortedString) {
    // repeat is a method where you input the number of occurrence. We just concatenate to result
    result = result + item.repeat(mp.get(item))
  }

  return result;

};

let s = "tree";
console.log(frequencySort(s));