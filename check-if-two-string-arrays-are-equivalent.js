let word1 = ["ab", "c"], word2 = ["a", "bc"];

const arrayStringsAreEqual = function (word1, word2) {

  // solution 1. join the arrays into strings and compare them

  // let str1 = word1.join("");
  // let str2 = word2.join("");

  // return str1 === str2;

  // solution 2. compare the arrays element by element

  let index_word_1 = 0, index_word_2 = 0, i = 0, j = 0;

  while (true) {

    // validate pointer for word in word1
    while (index_word_1 < word1.length && i === word1[index_word_1].length) {
      index_word_1++;
      i = 0;
    }

    // validate pointer for word in word2
    while (index_word_2 < word2.length && j === word2[index_word_2].length) {
      index_word_2++;
      j = 0;
    }

    // end of one (or both) array is reached
    if (index_word_1 === word1.length || index_word_2 === word2.length) {
      break;
    }

    if (word1[index_word_1][i] !== word2[index_word_2][j]) {
      return false;
    }

    i++;
    j++;

  }

  return index_word_1 === word1.length && index_word_2 === word2.length;

};



console.log(arrayStringsAreEqual(word1, word2));