/**
 * @param {number} n
 * @return {number}
 */
var numTilings = function (n) {

  if (n == 1 || n == 2) {
    return n;
  }
  let dp = []
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 5;
  for (let i = 4; i <= n; i++) {
    dp[i] = (2 * dp[i - 1] + dp[i - 3]) % 1000000007
  }
  return dp[n];

};

let n = 3;
console.log(numTilings(n));