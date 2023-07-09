/**
 * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function (text) {
  let min = text.length;
  let hash = {
    b: 0,
    a: 0,
    o: 0,
    l: 0,
    n: 0,
  };
  for (let i of text) {
    if ("balloon".includes(i)) {
      if (hash[i] !== undefined) {
        hash[i] = hash[i] + 1;
      } else {
        hash[i] = 1;
      }
    }
  }

  for (let letter in hash) {
    let count = hash[letter];
    if (letter == "l" || letter == "o") {
      count = Math.floor(count / 2);
    }
    if (count < min) {
      min = count;
    }
  }

  return min;
};

console.log(maxNumberOfBalloons("ballon"));
