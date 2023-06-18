#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution
{
private:
  vector<vector<int>> dp;

public:
  void init()
  {
    dp = vector<vector<int>>(20, vector<int>((1 << 14) + 5, -1));
  }

  int solve(const vector<int> &nums, int ult, int i, int mask)
  {
    if (i == nums.size())
    {
      return 1;
    }
    if (dp[ult + 1][mask] != -1)
    {
      return dp[ult + 1][mask];
    }
    int tot = 0;
    for (int j = 0; j < nums.size(); ++j)
    {
      if (mask & (1 << j))
      {
        continue;
      }
      if (ult == -1 || nums[ult] % nums[j] == 0 || nums[j] % nums[ult] == 0)
      {
        tot += solve(nums, j, i + 1, mask | (1 << j));
      }
      tot %= MOD;
    }
    dp[ult + 1][mask] = tot;
    return dp[ult + 1][mask];
  }

  int specialPerm(const vector<int> &nums)
  {
    init();
    return solve(nums, -1, 0, 0);
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 3, 2, 4};
  cout << sol.specialPerm(nums) << endl;
  return 0;
}