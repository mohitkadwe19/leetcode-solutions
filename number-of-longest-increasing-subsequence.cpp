#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findNumberOfLIS(vector<int> &nums)
  {
    int n = nums.size();

    vector<int> dp(n, 1);
    vector<int> cnt(n, 1);
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (nums[j] > nums[i] && 1 + dp[i] > dp[j])
        {
          dp[j] = 1 + dp[i];
          cnt[j] = cnt[i];
        }
        else if (nums[j] > nums[i] && 1 + dp[i] == dp[j])
        {
          cnt[j] += cnt[i];
        }
      }
      maxi = max(maxi, dp[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (dp[i] == maxi)
        ans += cnt[i];
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 3, 5, 4, 7};
  cout << sol.findNumberOfLIS(nums);
  return 0;
}