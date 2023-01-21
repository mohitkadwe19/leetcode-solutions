/**
 * @param {string} s
 * @return {string[]}
 */
var restoreIpAddresses = function (s) {

  let result = [];

  function dfs(s, path, index) {
    if (index === 4) {
      if (s.length === 0) {
        result.push(path.join('.'));
      }
      return;
    }

    for (let i = 1; i < 4; i++) {
      if (s.length < i) {
        break;
      }

      let part = s.substr(0, i);
      if (part.length > 1 && part[0] === '0') {
        continue;
      }

      if (Number(part) <= 255) {
        path.push(part);
        dfs(s.substr(i), path, index + 1);
        path.pop();
      }
    }
  }

  dfs(s, [], 0);

  return result;

};

let s = "25525511135";
let result = restoreIpAddresses(s);
console.log(result);