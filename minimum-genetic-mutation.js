/**
 * @param {string} start
 * @param {string} end
 * @param {string[]} bank
 * @return {number}
 */
var minMutation = function (start, end, bank) {

  let totalBanks = new Set(bank);
  let str = ['A', 'T', 'C', 'G'];
  let Q = [[start, 0]];
  let item, dist, i, j;

  if (!totalBanks.has(end)) {
    return -1;
  }

  while (Q.length > 0) {

    [item, dist] = Q.shift();

    if (item == end) {
      return dist;
    }

    for (i = 0; i < 8; i++) {

      for (j = 0; j < 4; j++) {

        if (item[i] == str[j]) {
          continue;
        }

        let val = item.slice(0, i) + str[j] + item.slice(i + 1);

        if (totalBanks.has(val)) {

          Q.push([val, dist + 1]);

          totalBanks.delete(val);
        }
      }
    }
  }
  return -1;
};

let start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"];
let result = minMutation(start, end, bank);
console.log(result);