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

vector<vector<int>> pathSum(TreeNode *root, int targetSum, vector<int> current = {}, vector<vector<int>> answer = {}, int sum = 0)
{
  if (!root)
  {
    return answer;
  }

  sum += root->val;
  current.push_back(root->val);

  if (sum == targetSum && !root->left && !root->right)
  {
    answer.push_back(current);
  }

  if (root->left)
  {
    answer = pathSum(root->left, targetSum, current, answer, sum);
  }
  if (root->right)
  {
    answer = pathSum(root->right, targetSum, current, answer, sum);
  }
  return answer;
}

class Solution
{
public:
  void sumOfNode(int target, vector<int> &member, vector<vector<int>> &ans, TreeNode *root)
  {
    if (root == NULL)
    {
      return;
    }
    member.push_back(root->val);
    target = target - root->val;

    if (root->left == NULL && root->right == NULL && target == 0)
    {
      ans.push_back(member);
    }

    sumOfNode(target, member, ans, root->left);

    sumOfNode(target, member, ans, root->right);

    member.pop_back();
  }

  vector<vector<int>> pathSum(TreeNode *root, int targetSum)
  {
    vector<int> member;
    vector<vector<int>> answer;
    sumOfNode(targetSum, member, answer, root);
    return answer;
  }
};

int main()
{
  Solution sol;
  int targetSum = 22;
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  root->right = new TreeNode(8);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->right->right->left = new TreeNode(5);
  root->right->right->right = new TreeNode(1);

  vector<vector<int>> ans = sol.pathSum(root, targetSum);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}