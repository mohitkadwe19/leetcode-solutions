/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function (s) {
  let vowels = 'aeiouAEIOU';
  let arr = s.split('');
  let i = 0;
  let j = arr.length - 1;
  while (i < j) {
    while (i < j && vowels.indexOf(arr[i]) === -1) {
      i++;
    }
    while (i < j && vowels.indexOf(arr[j]) === -1) {
      j--;
    }
    var tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    i++;
    j--;
  }
  return arr.join('');
};

let s = "hello";
let result = reverseVowels(s);
console.log(result);