#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(vector<int> &a, int k, int i, vector<int> &dp)
  {
    if (i >= a.size())
    {
      return 0;
    }
    if (dp[i] != -1)
    {
      return dp[i];
    }
    int take = 0;
    int nt = solve(a, k, i + 1, dp);

    if (a[i] <= k)
    {
      return dp[i] = max(solve(a, k, i + 2, dp) + 1, nt);
    }
    return dp[i] = nt;
  }

  bool check(vector<int> &a, int k, int req)
  {
    vector<int> dp(a.size());
    for (int i = 0; i < a.size(); i++)
    {
      dp[i] = -1;
    }
    int maxNumer = solve(a, k, 0, dp);
    return maxNumer >= req;
  }

  int minCapability(vector<int> &nums, int k)
  {
    int sum = 0;
    int exponential = 1000000000;
    while (sum + 1 < exponential)
    {
      int m = sum + (exponential - sum) / 2;
      if (check(nums, m, k))
      {
        exponential = m;
      }
      else
      {
        sum = m;
      }
    }
    return exponential;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int k = 3;
  cout << s.minCapability(nums, k) << endl;
  return 0;
}