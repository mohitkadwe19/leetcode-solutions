/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function (pattern, s) {

  let words = s.split(" ");
  if (words.length !== pattern.length) return false;

  let map = new Map();
  let set = new Set();

  for (let i = 0; i < pattern.length; i++) {
    let char = pattern[i];
    let word = words[i];

    if (map.has(char)) {
      if (map.get(char) !== word) return false;
    } else {
      if (set.has(word)) return false;
      map.set(char, word);
      set.add(word);
    }
  }

  return true;

};

let pattern = "abba", s = "dog cat cat dog";
console.log(wordPattern(pattern, s));