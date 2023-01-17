/**
 * @param {string} s
 * @return {number}
 */
var minFlipsMonoIncr = function (s) {

  let n = s.length;
  let dp = new Array(n + 1).fill(0);

  for (let i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + (s[i - 1] == '1' ? 1 : 0);
  }

  let result = Number.MAX_SAFE_INTEGER;
  for (let i = 0; i <= n; i++) {
    result = Math.min(result, dp[i] + n - i - (dp[n] - dp[i]));
  }

  return result;

};

let s = "00110";
let result = minFlipsMonoIncr(s);
console.log(result);