/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function (arr) {

  let map = new Map();
  for (let i = 0; i < arr.length; i++) {
    if (map.has(arr[i])) {
      map.set(arr[i], map.get(arr[i]) + 1);
    } else {
      map.set(arr[i], 1);
    }
  }

  if (map.size === new Set(map.values()).size) {
    return true;
  } else {
    return false;
  }

};
let arr = [1, 2];
console.log(uniqueOccurrences(arr));