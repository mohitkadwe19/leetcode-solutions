/** 
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * var guess = function(num) {}
 */

/**
 * @param {number} n
 * @return {number}
 */
var guessNumber = function (n) {

  let low = 1;
  let high = n;
  let mid = Math.floor((low + high) / 2);

  while (guess(mid) !== 0) {
    if (guess(mid) === 1) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
    mid = Math.floor((low + high) / 2);
  }

  return mid;

};

let n = 10, pick = 6;
console.log(guessNumber(n));