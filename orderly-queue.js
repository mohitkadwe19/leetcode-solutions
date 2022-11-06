/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var orderlyQueue = function (s, k) {
  if (k > 1) {
    return s.split('').sort().join('');
  }
  let result = s;
  for (let i = 1; i < s.length; i++) {
    const str = s.substring(i) + s.substring(0, i);
    if (str < result) {
      result = str;
    }
  }
  return result;
};

let s = "cba", k = 1
console.log(orderlyQueue(s, k))