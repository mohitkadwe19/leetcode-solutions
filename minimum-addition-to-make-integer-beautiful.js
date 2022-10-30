/**
 * @param {number} n
 * @param {number} target
 * @return {number}
 */

function sumDigits(n) {
  let sum = 0;

  while (n > 0) {
    sum += n % 10;
    n = Math.floor(n / 10);
  }

  return sum;
}

var makeIntegerBeautiful = function (n, target) {
  let ans = 0, modNumber = 1;

  while (sumDigits(n) > target) {

    modNumber *= 10;

    n -= ans;

    ans = modNumber - n % modNumber;

    n += ans;
  }

  return ans;
};

let n = 1, target = 1;
console.log(makeIntegerBeautiful(n, target));