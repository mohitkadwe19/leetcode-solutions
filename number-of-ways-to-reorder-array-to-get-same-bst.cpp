#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

class Solution
{
public:
  void PascalTriangle(int n, vector<vector<int>> &dp)
  {
    for (int i = 0; i <= n; i++)
    {
      dp[i] = vector<int>(i + 1, 1);
      for (int j = 1; j < i; j++)
      {
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
      }
    }
  }
  int dfs(vector<int> &nums, vector<vector<int>> &dp)
  {
    vector<int> leftSubTree, rightSubTree;
    int n = nums.size();

    if (n < 3)
    {
      return 1;
    }

    for (int i = 1; i < n; i++)
    {
      if (nums[i] >= nums[0])
        rightSubTree.push_back(nums[i]);
      if (nums[i] < nums[0])
        leftSubTree.push_back(nums[i]);
    }

    int left = dfs(leftSubTree, dp) % mod;
    int right = dfs(rightSubTree, dp) % mod;
    int ele_atLeft = leftSubTree.size();

    return (1ll * (1ll * dp[n - 1][ele_atLeft] * 1ll * left) % mod * right) % mod;
  }
  int numOfWays(vector<int> &nums)
  {
    int n = nums.size();
    vector<vector<int>> dp(n + 1);
    PascalTriangle(n, dp);
    int ways = dfs(nums, dp) - 1;
    return ways;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {2, 1, 3};
  cout << s.numOfWays(nums) << endl;
  return 0;
}