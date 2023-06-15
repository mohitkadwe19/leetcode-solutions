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
  int maxLevelSum(TreeNode *root)
  {
    if (!root)
      return 0;
    int maxSum = INT_MIN, maxLevel = 0, level = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      int size = q.size();
      int sum = 0;
      level++;
      while (size--)
      {
        TreeNode *node = q.front();
        q.pop();
        sum += node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      if (sum > maxSum)
      {
        maxSum = sum;
        maxLevel = level;
      }
    }
    return maxLevel;
  }
};

int main()
{
  Solution sol;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(7);
  root->right = new TreeNode(0);
  root->left->left = new TreeNode(7);
  root->left->right = new TreeNode(-8);
  cout << sol.maxLevelSum(root) << endl;
  return 0;
}