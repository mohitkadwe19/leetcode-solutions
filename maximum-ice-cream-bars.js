/**
 * @param {number[]} costs
 * @param {number} coins
 * @return {number}
 */
var maxIceCream = function (costs, coins) {

  let maxIceCreamBars = 0;
  let sortedCosts = costs.sort((a, b) => a - b);

  for (let i = 0; i < sortedCosts.length; i++) {
    if (coins >= sortedCosts[i]) {
      coins -= sortedCosts[i];
      maxIceCreamBars++;
    }
  }

  return maxIceCreamBars;

};

let costs = [1, 3, 2, 4, 1], coins = 7;
let output = maxIceCream(costs, coins);
console.log(output);