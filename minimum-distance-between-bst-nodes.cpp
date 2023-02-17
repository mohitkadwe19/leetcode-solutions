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
  int minDiffInBST(TreeNode *root)
  {
    int minDiff = INT_MAX;
    int prev = -1;
    stack<TreeNode *> st;
    while (root != nullptr || !st.empty())
    {
      while (root != nullptr)
      {
        st.push(root);
        root = root->left;
      }
      root = st.top();
      st.pop();
      if (prev != -1)
      {
        minDiff = min(minDiff, root->val - prev);
      }
      prev = root->val;
      root = root->right;
    }
    return minDiff;
  }
};

int main()
{
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  Solution *sol = new Solution();
  cout << sol->minDiffInBST(root) << endl;
  return 0;
}