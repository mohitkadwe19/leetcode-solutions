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
  void inOrder(TreeNode *root, vector<int> &v)
  {
    if (root == NULL)
      return;
    inOrder(root->left, v);
    v.push_back(root->val);
    inOrder(root->right, v);
  }
  bool findTarget(TreeNode *root, int k)
  {
    vector<int> v;
    inOrder(root, v);
    int i = 0, j = v.size() - 1;
    while (i < j)
    {
      if (v[i] + v[j] == k)
      {
        return true;
      }
      else if (v[i] + v[j] < k)
      {
        i++;
      }
      else
      {
        j--;
      }
    }
    return false;
  }
};

int main()
{
  Solution s;
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);
  cout << s.findTarget(root, 9) << endl;
}