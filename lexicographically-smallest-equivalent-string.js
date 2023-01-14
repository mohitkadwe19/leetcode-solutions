/**
 * @param {string} s1
 * @param {string} s2
 * @param {string} baseStr
 * @return {string}
 */


var findRoot = function (c, map) {
  if (!map.has(c)) {
    map.set(c, c);
    return c;
  }
  let root = map.get(c);
  if (root != c) {
    root = findRoot(root, map);
    map.set(c, root);
  }
  return root;
}

var smallestEquivalentString = function (s1, s2, baseStr) {

  let map = new Map();
  for (let i = 0; i < s1.length; i++) {
    let c1 = s1[i], c2 = s2[i];
    let c1Root = findRoot(c1, map), c2Root = findRoot(c2, map);
    if (c1Root != c2Root) {
      if (c1Root < c2Root) {
        map.set(c2Root, c1Root);
      } else {
        map.set(c1Root, c2Root);
      }
    }
  }

  let result = "";
  for (let i = 0; i < baseStr.length; i++) {
    let c = baseStr[i];
    let root = findRoot(c, map);
    result += root;
  }

  return result;

};

let s1 = "parker", s2 = "morris", baseStr = "parser";
console.log(smallestEquivalentString(s1, s2, baseStr));