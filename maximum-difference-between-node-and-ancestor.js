
// Definition for a binary tree node.
function TreeNode(val, left, right) {
  this.val = (val === undefined ? 0 : val)
  this.left = (left === undefined ? null : left)
  this.right = (right === undefined ? null : right)
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxAncestorDiff = function (root) {

  let output = 0;

  // traverse down to Leaf node
  // update min as we traverse down the tree

  const traverse = (root, min, max) => {
    // if leaf, calculate max diff
    if (!root) return output = Math.max(output, max - min);

    // update min/max
    min = Math.min(min, root.val);
    max = Math.max(max, root.val);

    // traverse Left/Right
    const L = traverse(root.left, min, max);
    const R = traverse(root.right, min, max);

  }

  traverse(root, root.val, root.val);
  return output;

};

let root = [8, 3, 10, 1, 6, null, 14, null, null, 4, 7, 13];

console.log(maxAncestorDiff(root));
