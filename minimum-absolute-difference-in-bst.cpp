#include <bits/stdc++.h>
using namespace std;

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
  void inorder(TreeNode *root, int &prev, int &ans)
  {
    if (root == NULL)
      return;
    inorder(root->left, prev, ans);
    if (prev != -1)
      ans = min(ans, root->val - prev);
    prev = root->val;
    inorder(root->right, prev, ans);
  }
  int getMinimumDifference(TreeNode *root)
  {
    int ans = INT_MAX, prev = -1;
    inorder(root, prev, ans);
    return ans;
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(2);
  Solution sol;
  cout << sol.getMinimumDifference(root) << endl;
  return 0;
}