/**
 * @param {number[]} tasks
 * @return {number}
 */
var minimumRounds = function (tasks) {

  let mp = new Map();

  for (let i = 0; i < tasks.length; i++) {
    if (mp[tasks[i]]) {
      mp[tasks[i]]++;
    }
    else {
      mp[tasks[i]] = 1;
    }
  }

  let ans = 0;

  for (let obj in mp) {
    if (mp[obj] == 1) return -1;
    else {
      ans += Math.ceil(mp[obj] / 3.0);
    }
  }

  return ans;

};

let tasks = [2, 2, 3, 3, 2, 4, 4, 4, 4, 4];
console.log(minimumRounds(tasks));