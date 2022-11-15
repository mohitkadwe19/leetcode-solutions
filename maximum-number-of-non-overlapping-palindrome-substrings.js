function isPalindrome(s) {
  let l = 0;
  let h = s.length - 1;
  while (l < h) {
    if (s[l] != s[h]) return false;
    l++;
    h--;
  }
  return true;
}


/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var maxPalindromes = function (s, k) {

  let res = 0;
  let temp = "";
  let i = 0;
  let j = 0;
  let t = 0;

  while (i <= s.length - k) {
    j = i;
    temp = "";
    t = i + 1;
    while (j < s.length) {
      temp += s[j];
      if (temp.length >= k) {
        if (isPalindrome(temp)) {
          res++;
          t = j + 1;
          temp = "";
        }
      }
      j++;
    }
    i = t;
  }
  return res;

};

let s = "sjbxiufnaanqkwsqswkqrcznzcddhtuhtthuttjfuufjtcfywgecegwyhhnnhtozczirynhhnyrire", k = 3;
console.log(maxPalindromes(s, k));