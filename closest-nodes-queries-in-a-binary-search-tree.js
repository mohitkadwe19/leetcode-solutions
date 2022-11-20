/**
 * Definition for a binary tree node.
 */
/**
 * @param {TreeNode} root
 * @param {number[]} queries
 * @return {number[][]}
 */

function TreeNode(val, left, right) {
  this.val = (val === undefined ? 0 : val)
  this.left = (left === undefined ? null : left)
  this.right = (right === undefined ? null : right)
}

function findMin(arr, num) {
  let ans = -1;
  let start = 0;
  let end = arr.length - 1;
  while (start <= end) {
    let mid = parseInt((start + end) / 2);
    if (arr[mid] <= num) {
      ans = arr[mid];
      start = mid + 1;
    }
    else {
      end = mid - 1;
    }
  }
  return ans;
}

function findMax(arr, num) {
  let ans = 0;
  let start = 0;
  let end = arr.length - 1;
  while (start <= end) {
    let mid = parseInt((start + end) / 2);
    if (arr[mid] >= num) {
      ans = arr[mid];
      end = mid - 1;
    }
    else {
      start = mid + 1;
    }
  }
  return ans;
}

function findMinAndMin(arr, num) {
  let ans = new Array(2).fill(0);

  ans[0] = findMin(arr, num);
  ans[1] = findMax(arr, num);

  return ans;
}

function preorderTraversal(root) {
  let arr = [];
  function traverse(node) {
    if (node) {
      arr.push(node.val);
      traverse(node.left);
      traverse(node.right);
    }
  }
  traverse(root);
  return arr;
}

var closestNodes = function (root, queries) {

  let arr = preorderTraversal(root);
  arr.sort((a, b) => a - b);
  let ans = new Array(queries.length).fill(0);
  for (let i = 0; i < queries.length; i++) {
    ans[i] = findMinAndMin(arr, queries[i]);
  }
  return ans;

};

// [6,2,13,1,4,9,15,null,null,null,null,null,null,14][2, 5, 16]
let root = new TreeNode(10);
root.left = new TreeNode(5);
root.right = new TreeNode(15);
root.left.left = new TreeNode(2);
root.left.right = new TreeNode(5);
root.right.left = new TreeNode(13);
root.right.right = new TreeNode(22);
root.left.left.left = new TreeNode(1);
root.right.left.right = new TreeNode(14);

let queries = [2, 5, 16];
console.log(closestNodes(root, queries));