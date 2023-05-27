#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string stoneGameIII(vector<int> &stoneValue)
  {
    int n = stoneValue.size();
    vector<int> dp(n + 1, INT_MIN);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      int sum = 0;
      for (int j = i; j < min(i + 3, n); j++)
      {
        sum += stoneValue[j];
        dp[i] = max(dp[i], sum - dp[j + 1]);
      }
    }
    if (dp[0] > 0)
      return "Alice";
    else if (dp[0] < 0)
      return "Bob";
    else
      return "Tie";
  }
};

int main()
{
  Solution s;
  vector<int> stoneValue = {1, 2, 3, 7};
  cout << s.stoneGameIII(stoneValue) << endl;
  return 0;
}