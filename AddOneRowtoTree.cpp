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
  TreeNode *addOneRow(TreeNode *root, int val, int depth)
  {
    if (depth == 1)
    {
      TreeNode *newNode = new TreeNode(val);
      newNode->left = root;
      return newNode;
    }
    queue<TreeNode *> q;
    q.push(root);
    int level = 1;
    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        TreeNode *node = q.front();
        q.pop();
        if (level == depth - 1)
        {
          TreeNode *left = node->left;
          TreeNode *right = node->right;
          node->left = new TreeNode(val);
          node->right = new TreeNode(val);
          node->left->left = left;
          node->right->right = right;
        }
        else
        {
          if (node->left)
            q.push(node->left);
          if (node->right)
            q.push(node->right);
        }
      }
      level++;
    }
    return root;
  }
  void printTree(TreeNode *root)
  {
    if (root == NULL)
      return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
  }
};

int main()
{
  Solution *s = new Solution();
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(1);
  root->right->left = new TreeNode(5);
  int val = 1;
  int depth = 2;
  TreeNode *ans = s->addOneRow(root, val, depth);
  s->printTree(ans);
  return 0;
}