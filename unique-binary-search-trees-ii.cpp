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
  vector<TreeNode *> generateTree(int size, int s, int e)
  {
    if (size == 0)
    {
      return {NULL};
    }
    if (size == 1)
    {
      TreeNode *temp = new TreeNode(s);
      return {temp};
    }
    vector<TreeNode *> ans;
    for (int i = s; i <= e; i++)
    {
      vector<TreeNode *> v1 = generateTree(i - s, s, i - 1);
      vector<TreeNode *> v2 = generateTree(e - i, i + 1, e);
      for (int j = 0; j < v1.size(); j++)
      {
        for (int k = 0; k < v2.size(); k++)
        {
          TreeNode *temp = new TreeNode(i);
          temp->left = v1[j];
          temp->right = v2[k];
          ans.push_back(temp);
        }
      }
    }
    return ans;
  }
  vector<TreeNode *> generateTrees(int n)
  {
    return generateTree(n, 1, n);
  }
};
int main()
{
  Solution sol;
  int n = 3;
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);

  vector<TreeNode *> ans = sol.generateTrees(n);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i]->val; j++)
    {
      cout << ans[i]->val << " ";
    }
    cout << endl;
  }
  return 0;
}