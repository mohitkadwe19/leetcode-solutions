/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */

class TreeNode {
  constructor(val, left, right) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxPathSum = function (root) {

  let max = Number.MIN_SAFE_INTEGER;

  function dfs(node) {
    if (node === null) {
      return 0;
    }

    let left = dfs(node.left);
    let right = dfs(node.right);

    let sum = node.val;
    if (left > 0) {
      sum += left;
    }
    if (right > 0) {
      sum += right;
    }

    max = Math.max(max, sum);

    return node.val + Math.max(left, right, 0);
  }

  dfs(root);
  return max;

};

let root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
console.log(maxPathSum(root));