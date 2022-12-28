/**
 * @param {number[]} piles
 * @param {number} k
 * @return {number}
 */
var minStoneSum = function (piles, k) {

  let j = 0;
  let total = 0;
  let counter = 0;

  piles.sort((a, b) => b - a);

  while (counter < k) {

    if (j >= piles.length - 1) {
      j = 0; piles.sort((a, b) => b - a);
    }
    if (piles[j] < piles[j + 1]) {
      j++;
    }
    if (piles[j] < piles[0]) {
      j = 0; piles.sort((a, b) => b - a);
    }
    piles[j] -= Math.floor(piles[j] / 2);
    counter++;
  }
  for (let i = 0; i < piles.length; i++) {
    total += piles[i];
  }
  return total;

};

let piles = [5, 4, 9], k = 2;
let result = minStoneSum(piles, k);
console.log(result);