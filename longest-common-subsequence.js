/**
 * @param {string} text1
 * @param {string} text2
 * @return {number}
 */
var longestCommonSubsequence = function (text1, text2) {

  if (text1 === text2) {
    return text1.length;
  }

  let arr = [];
  for (let i = 0; i < text1.length + 1; i++) {
    arr.push(new Array(text2.length + 1).fill(0));
  }
  for (let i = 1; i < arr.length; i++) {
    for (let j = 1; j < arr[0].length; j++) {
      if (text1[i - 1] === text2[j - 1]) {
        arr[i][j] = arr[i - 1][j - 1] + 1;
      }
      else {
        arr[i][j] = Math.max(arr[i - 1][j], arr[i][j - 1]);
      }
    }
  }

  return arr[text1.length][text2.length];

};

let text1 = "abcde", text2 = "ace";
console.log(longestCommonSubsequence(text1, text2));