#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  bool flag = false;
  void check(TreeNode *root, TreeNode *target, unordered_map<TreeNode *, TreeNode *> &parent)
  {

    if (root == nullptr)
      return;
    if (root->val == target->val)
    {
      flag = true;
    }
    parent[root->left] = root;
    parent[root->right] = root;
    check(root->left, target, parent);
    check(root->right, target, parent);
  }

  void solve(TreeNode *root, int k, vector<int> &ans,
             unordered_map<TreeNode *, TreeNode *> &parent, unordered_map<TreeNode *, int> &main, int h)
  {

    if (root == nullptr)
      return;
    if (main.find(root) != main.end())
    {
      return;
    }
    main[root] = h + 1;
    if (h == k)
    {
      ans.push_back(root->val);
    }
    solve(root->left, k, ans, parent, main, h + 1);
    solve(root->right, k, ans, parent, main, h + 1);
    solve(parent[root], k, ans, parent, main, main[root]);
  }

  vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
  {

    unordered_map<TreeNode *, TreeNode *> parent;
    unordered_map<TreeNode *, int> main;
    vector<int> ans;
    check(root, target, parent);
    if (root == NULL || flag == false)
      return ans;
    solve(target, k, ans, parent, main, 0);
    return ans;
  }
};

int main()
{
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  TreeNode *target = root->left->right;
  int k = 2;
  Solution sol;
  vector<int> result = sol.distanceK(root, target, k);
  for (auto i : result)
    cout << i << " ";
  cout << endl;
  return 0;
}