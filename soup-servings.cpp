#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double f(vector<vector<double>> &dp, int a, int b, double p)
  {
    if (a <= 0 && b <= 0)
    {
      return p / 2;
    }
    if (a <= 0)
    {
      return p;
    }
    if (b <= 0)
      return 0;

    if (dp[a][b] != -1)
      return dp[a][b];

    return dp[a][b] = f(dp, a - 100, b, p * 0.25) + f(dp, a - 75, b - 25, p * 0.25) + f(dp, a - 50, b - 50, p * 0.25) + f(dp, a - 25, b - 75, p * 0.25);
  }
  double soupServings(int n)
  {
    if (n >= 4800)
      return 1;
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));
    return f(dp, n, n, 1);
    ;
  }
};

int main()
{
  Solution obj;
  cout << obj.soupServings(50) << endl;
  return 0;
}