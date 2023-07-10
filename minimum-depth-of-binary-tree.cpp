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
  int minDepth(TreeNode *root)
  {
    if (root == NULL)
    {
      return 0;
    }
    int count = 1;
    if (root->left == NULL && root->right != NULL)
    {
      count += minDepth(root->right);
    }
    else if (root->right == NULL && root->left != NULL)
    {
      count += minDepth(root->left);
    }
    else
    {
      count = count + min(minDepth(root->left), minDepth(root->right));
    }
    return count;
  }
};

int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  Solution s;
  cout << s.minDepth(root) << endl;
  return 0;
}