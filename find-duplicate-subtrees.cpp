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
  string helper(TreeNode *root, unordered_map<string, int> &mp, vector<TreeNode *> &ans)
  {
    if (root == NULL)
    {
      return "";
    }
    string s = "(";
    s += helper(root->left, mp, ans);
    s += to_string(root->val);
    s += helper(root->right, mp, ans);
    s += ")";
    mp[s]++;
    if (mp[s] == 2)
    {
      ans.push_back(root);
    }
    return s;
  }
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
  {
    vector<TreeNode *> ans;
    unordered_map<string, int> mp;
    helper(root, mp, ans);
    return ans;
  }
};

int main()
{
  Solution *sol = new Solution();
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(2);
  root->right->left->left = new TreeNode(4);
  root->right->right = new TreeNode(4);
  vector<TreeNode *> ans = sol->findDuplicateSubtrees(root);
  for (auto i : ans)
  {
    cout << i->val << " ";
  }
  cout << endl;
  return 0;
}