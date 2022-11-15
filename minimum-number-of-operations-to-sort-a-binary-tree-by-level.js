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
var minimumOperations = function (root) {

  if (!root) return [];

  let myQueue = [root];
  let res = [];

  const getCurrentLevelNodes = () => {
    let counter = myQueue.length;
    let levelNodes = [];
    while (counter > 0) {
      let curNode = myQueue.shift();
      levelNodes.push(curNode.val);
      if (curNode.left)
        myQueue.push(curNode.left);
      if (curNode.right)
        myQueue.push(curNode.right);
      counter--;
    }
    return levelNodes;
  }


  while (myQueue.length) {
    let levelNodes = getCurrentLevelNodes();
    res.push(levelNodes);
  }

  return res;


};


let root = [1, 4, 3, 7, 6, 8, 5, null, null, null, null, 9, null, 10];
console.log(minimumOperations(root));