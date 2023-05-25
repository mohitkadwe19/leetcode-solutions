#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double new21Game(int n, int k, int maxPts)
  {
    if (k == 0 || n >= k + maxPts)
      return 1.0;
    vector<double> dp(n + 1);
    dp[0] = 1.0;
    double wSum = 1.0, ans = 0.0;
    for (int i = 1; i <= n; ++i)
    {
      dp[i] = wSum / maxPts;
      if (i < k)
        wSum += dp[i];
      else
        ans += dp[i];
      if (i - maxPts >= 0)
        wSum -= dp[i - maxPts];
    }
    return ans;
  }
};

int main()
{
  int n = 10, k = 1, maxPts = 10;
  Solution sol;
  cout << sol.new21Game(n, k, maxPts) << endl;
  return 0;
}