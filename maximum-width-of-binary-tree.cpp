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
  int widthOfBinaryTree(TreeNode *root)
  {
    if (root == nullptr)
    {
      return 0;
    }

    int max_width = 1;
    // taking the max_width
    queue<pair<TreeNode *, int>> q;
    // make the queue<pair<TreeNode*, int into q;
    q.push({root, 0});

    while (!q.empty())
    {

      int level_size = q.size();
      int start_index = q.front().second;
      int end_index = q.back().second;
      // define the size, index, from front to back depending upon size
      max_width = max(max_width, end_index - start_index + 1);

      for (int i = 0; i < level_size; ++i)
      {
        auto node_index_pair = q.front();
        // node pair for front
        TreeNode *node = node_index_pair.first;

        int node_index = node_index_pair.second - start_index;
        q.pop();

        if (node->left != nullptr)
        { // node into  left
          q.push({node->left, 2LL * node_index + 1});
          // push the node into left into the node's index,
        }

        if (node->right != nullptr)
        {
          q.push({node->right, 2LL * node_index + 2});
        } // push the left node and the index node will be added into it,
      }
    }
    //
    return max_width;
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(3);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(5);

  Solution *sol = new Solution();
  cout << sol->widthOfBinaryTree(root) << endl;
  return 0;
}