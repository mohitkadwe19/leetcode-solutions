#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
  {
    int m = group.size();
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
    for (int i = 0; i <= m; i++)
      dp[i][0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
      int members = group[i - 1], earn = profit[i - 1];
      for (int j = 0; j <= n; j++)
      {
        for (int k = 0; k <= minProfit; k++)
        {
          dp[i][j][k] = dp[i - 1][j][k];
          if (j >= members)
            dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - members][max(0, k - earn)]) % 1000000007;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
      ans = (ans + dp[m][i][minProfit]) % 1000000007;
    }
    return ans;
  }
};

int main()
{
  int n = 5, minProfit = 3;
  vector<int> group = {2, 2}, profit = {2, 3};
  Solution s;
  cout << s.profitableSchemes(n, minProfit, group, profit) << endl;
  return 0;
}