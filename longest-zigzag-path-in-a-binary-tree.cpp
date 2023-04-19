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
  pair<int, int> helper(TreeNode *root, int &ans)
  {
    if (root == NULL)
      return {0, 0};
    pair<int, int> l = helper(root->left, ans);
    ans = max(ans, 1 + l.second);
    pair<int, int> r = helper(root->right, ans);
    ans = max(ans, 1 + r.first);
    return {1 + l.second, 1 + r.first};
  }
  int longestZigZag(TreeNode *root)
  {
    int ans = 0;
    helper(root, ans);
    return ans - 1;
  }
};

int main()
{
  return 0;
}