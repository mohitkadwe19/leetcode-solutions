/**
 * @param {number[]} skill
 * @return {number}
 */
var dividePlayers = function (skill) {

  let ans = 0, n = skill.length;

  // sort the array
  skill.sort((a, b) => a - b);

  for (let i = 0; i < n / 2; i++) {
    if (skill[i] + skill[n - i - 1] != skill[0] + skill[n - 1]) {
      return -1;
    }
    ans += skill[i] * skill[n - i - 1];
  }
  return ans;

};
let skill = [3, 2, 5, 1, 3, 4];
console.log(dividePlayers(skill));