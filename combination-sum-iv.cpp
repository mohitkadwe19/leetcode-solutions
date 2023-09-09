#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getResult(vector<int> &dp, vector<int> &nums, int target)
  {
    if (target < 0)
    {
      return 0;
    }
    if (target == 0)
    {
      return 1;
    }
    if (dp[target] != -1)
    {
      return dp[target];
    }
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      ans += getResult(dp, nums, target - nums[i]);
    }
    dp[target] = ans;
    return dp[target];
  }
  int combinationSum4(vector<int> &nums, int target)
  {
    vector<int> dp(target + 1, -1);
    return getResult(dp, nums, target);
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3};
  int target = 4;
  cout << sol.combinationSum4(nums, target) << endl;
  return 0;
}