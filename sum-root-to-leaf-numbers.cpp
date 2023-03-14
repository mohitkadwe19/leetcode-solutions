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
  int sumNumbers(TreeNode *root)
  {
    return dfs(root, 0);
  }

  int dfs(TreeNode *root, int sum)
  {
    if (!root)
    {
      return 0;
    }
    sum = sum * 10 + root->val;
    if (!root->left && !root->right)
    {
      return sum;
    }
    return dfs(root->left, sum) + dfs(root->right, sum);
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  Solution s;
  cout << s.sumNumbers(root) << endl;
  return 0;
}