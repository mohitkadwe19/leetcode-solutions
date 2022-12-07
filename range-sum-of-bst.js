
// Definition for a binary tree node.

function TreeNode(val, left, right) {
  this.val = (val === undefined ? 0 : val)
  this.left = (left === undefined ? null : left)
  this.right = (right === undefined ? null : right)
}

/**
 * @param {TreeNode} root
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var rangeSumBST = function (root, L, R, sum = 0) {
  if (!root) return sum;
  if (root.val <= R && root.val >= L) {
    sum += root.val;
  }
  return sum + rangeSumBST(root.left, L, R) + rangeSumBST(root.right, L, R);
};

let root = [10, 5, 15, 3, 7, null, 18], low = 7, high = 15;

console.log(rangeSumBST(root, low, high));