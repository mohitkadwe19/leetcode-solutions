/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxProduct = function (root) {

  const mod = Math.pow(10, 9) + 7;


  function dfs(node) {
    if (!node) {
      return 0;
    }
    let left = dfs(node.left)
    let right = dfs(node.right)

    return (node.val + left + right) % mod;
  }

  let total = dfs(root);

  let max = -Infinity;

  function maxP(node) {
    if (!node) return 0;
    let left = maxP(node.left);
    let right = maxP(node.right)
    max = Math.max(max, left * (total - left))
    max = Math.max(max, right * (total - right))
    return (node.val + left + right) % mod;
  }

  maxP(root)

  return max % mod;

};

let root = [1, 2, 3, 4, 5, 6];
let output = maxProduct(root);
console.log(output);