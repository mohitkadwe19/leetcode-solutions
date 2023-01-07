/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function (gas, cost) {

  let total = 0, sum = 0, start = 0;

  for (let i = 0; i < gas.length; i++) {
    total += gas[i] - cost[i];
    sum += gas[i] - cost[i];
    if (sum < 0) {
      start = i + 1;
      sum = 0;
    }
  }

  return total < 0 ? -1 : start;

};

let gas = [1, 2, 3, 4, 5], cost = [3, 4, 5, 1, 2];
console.log(canCompleteCircuit(gas, cost));