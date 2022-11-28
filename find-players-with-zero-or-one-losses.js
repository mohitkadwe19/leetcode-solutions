/**
 * @param {number[][]} matches
 * @return {number[][]}
 */
var findWinners = function (matches) {

  const lostZeroMatch = [];
  const lostOneMatch = [];

  const lossesCount = new Array(100001).fill(-1);

  for (const match of matches) {
    const winner = match[0], loser = match[1];

    if (lossesCount[winner] === -1)
      lossesCount[winner] = 0;

    if (lossesCount[loser] === -1)
      lossesCount[loser] = 1;
    else
      lossesCount[loser]++;
  }

  for (let i = 1; i < 100001; i++) {
    if (lossesCount[i] === 0)
      lostZeroMatch.push(i);
    else if (lossesCount[i] === 1)
      lostOneMatch.push(i);
  }

  return [lostZeroMatch, lostOneMatch];

};

let matches = [[1, 3], [2, 3], [3, 6], [5, 6], [5, 7], [4, 5], [4, 8], [4, 9], [10, 4], [10, 9]];
console.log(findWinners(matches));