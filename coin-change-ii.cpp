#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int change(int amount, vector<int> &coins)
  {
    unordered_map<int, int> dp;
    int n = coins.size();
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
      for (int j = coins[i]; j <= amount; j++)
      {
        dp[j] += dp[j - coins[i]];
      }
    }
    return dp[amount];
  }
};

int main()
{
  Solution s;
  vector<int> coins = {1, 2, 5};
  int amount = 5;
  cout << s.change(amount, coins) << endl;
  return 0;
}