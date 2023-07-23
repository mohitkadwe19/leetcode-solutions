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
  vector<TreeNode *> allPossibleFBT(int n)
  {
    vector<TreeNode *> ans;
    if (n == 1)
    {
      ans.push_back(new TreeNode(0));
      return ans;
    }
    for (int i = 1; i < n; i += 2)
    {
      vector<TreeNode *> left = allPossibleFBT(i);
      vector<TreeNode *> right = allPossibleFBT(n - i - 1);
      for (TreeNode *l : left)
      {
        for (TreeNode *r : right)
        {
          TreeNode *root = new TreeNode(0);
          root->left = l;
          root->right = r;
          ans.push_back(root);
        }
      }
    }
    return ans;
  }

  void printTree(TreeNode *root)
  {
    if (root == NULL)
    {
      return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
  }
};

int main()
{
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(1);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(7);

  Solution *sol = new Solution();
  vector<TreeNode *> ans = sol->allPossibleFBT(3);
  for (int i = 0; i < ans.size(); i++)
  {
    sol->printTree(ans[i]);
    cout << endl;
  }

  return 0;
}