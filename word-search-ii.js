/**
 * @param {character[][]} board
 * @param {string[]} words
 * @return {string[]}
 */

var findWords = function (board, words) {
  let result = [];

  let root = buildTrie(words);

  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[0].length; j++) {
      dfs(root, board, i, j, result);
    }
  }

  return result;
};

var dfs = function (node, board, row, col, result) {
  if (node.end) {
    result.push(node.end);
    node.end = null;
  }

  if (row < 0 || row >= board.length || col < 0 || col >= board[0].length) {
    return;
  }

  if (!node[board[row][col]]) return;

  let char = board[row][col];
  board[row][col] = '-';

  dfs(node[char], board, row + 1, col, result);
  dfs(node[char], board, row - 1, col, result);
  dfs(node[char], board, row, col + 1, result);
  dfs(node[char], board, row, col - 1, result);

  board[row][col] = char;
}

var buildTrie = function (words) {
  let root = {};

  for (let word of words) {
    let pointer = root;

    for (let char of word) {
      if (!pointer[char]) pointer[char] = {};
      pointer = pointer[char];
    }

    pointer.end = word;
  }

  return root;
}

let board = [["o", "a", "a", "n"], ["e", "t", "a", "e"], ["i", "h", "k", "r"], ["i", "f", "l", "v"]], words = ["oath", "pea", "eat", "rain"];
console.log(findWords(board, words));