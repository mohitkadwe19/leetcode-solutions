#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestArithSeqLength(vector<int> &nums)
  {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2001, 1));
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        int diff = nums[i] - nums[j] + 1000;
        dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
        ans = max(ans, dp[i][diff]);
      }
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {3, 6, 9, 12};
  cout << sol.longestArithSeqLength(nums) << endl;
  return 0;
}