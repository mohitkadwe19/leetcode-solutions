#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numRollsToTarget(int n, int k, int target)
  {
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= target; j++)
      {
        for (int l = 1; l <= k; l++)
        {
          if (j - l >= 0)
          {
            dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % mod;
          }
        }
      }
    }
    return dp[n][target];
  }
};

int main()
{
  Solution s;
  cout << s.numRollsToTarget(1, 6, 3) << endl;
  cout << s.numRollsToTarget(2, 6, 7) << endl;
  cout << s.numRollsToTarget(2, 5, 10) << endl;
  cout << s.numRollsToTarget(1, 2, 3) << endl;
  cout << s.numRollsToTarget(30, 30, 500) << endl;
  return 0;
}