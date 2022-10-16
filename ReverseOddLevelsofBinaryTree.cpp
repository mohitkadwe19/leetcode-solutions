#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  TreeNode *reverseOddLevels(TreeNode *root)
  {
    if (!root)
    {
      return NULL;
    }
    else
    {
        }
  }
  TreeNode *printTree(TreeNode *root)
  {
    if (root == NULL)
      return NULL;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
  }
};

int main()
{
  Solution sol;
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(3);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(8);
  root->left->right = new TreeNode(13);
  root->right->left = new TreeNode(21);
  root->right->right = new TreeNode(34);

  // reverse odd levels of the treeNode
  cout << sol.reverseOddLevels(root) << endl;

  // print the tree
  cout << sol.printTree(root) << endl;
}