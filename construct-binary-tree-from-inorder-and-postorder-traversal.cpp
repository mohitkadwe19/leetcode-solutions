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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    int n = inorder.size();
    int m = postorder.size();
    if (n == 0 || m == 0)
    {
      return NULL;
    }
    int rootVal = postorder[m - 1];
    TreeNode *root = new TreeNode(rootVal);
    int rootIndex = -1;
    for (int i = 0; i < n; i++)
    {
      if (inorder[i] == rootVal)
      {
        rootIndex = i;
        break;
      }
    }
    vector<int> inLeft(inorder.begin(), inorder.begin() + rootIndex);
    vector<int> inRight(inorder.begin() + rootIndex + 1, inorder.end());
    vector<int> postLeft(postorder.begin(), postorder.begin() + inLeft.size());
    vector<int> postRight(postorder.begin() + inLeft.size(), postorder.end() - 1);
    root->left = buildTree(inLeft, postLeft);
    root->right = buildTree(inRight, postRight);
    return root;
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
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  Solution s;
  vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
  vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
  TreeNode *ans = s.buildTree(inorder, postorder);
  s.printTree(ans);
  return 0;
}