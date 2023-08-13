#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool solve(int i, vector<int> &nums, vector<int> &dp)
  {
    if (i == nums.size())
      return true;
    if (dp[i] != -1)
      return dp[i];
    // for size 2
    if (i < nums.size() - 1 && nums[i] == nums[i + 1])
    {
      if (solve(i + 2, nums, dp) == true)
        return dp[i] = true;
    }
    // for size 3
    if (i < nums.size() - 2 && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
    {
      if (solve(i + 3, nums, dp))
        return dp[i] = true;
    }
    // for size 3 case 2
    if (i < nums.size() - 2 && nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2])
    {
      if (solve(i + 3, nums, dp))
        return dp[i] = true;
    }
    return dp[i] = false;
  }
  bool validPartition(vector<int> &nums)
  {

    int i = 0;
    vector<int> dp(nums.size(), -1);
    return solve(i, nums, dp);
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  cout << s.validPartition(nums) << endl;
  return 0;
}