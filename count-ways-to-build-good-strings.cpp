#include <bits/stdc++.h>
using namespace std;

class Solution
{
  int mod = 1000000007;

public:
  int countGoodStrings(int low, int high, int zero, int one)
  {
    vector<int> dp(high + max(zero, one), 0);

    dp[high] = 1;

    for (int i = high - 1; i >= 0; --i)
    {
      int takeOne = dp[i + one];
      int takeZero = dp[i + zero];
      dp[i] = ((takeOne + takeZero) + (i >= low)) % mod;
    }

    return dp[0];
  }
};

int main()
{
  int low = 3, high = 3, zero = 1, one = 1;
  Solution sol;
  cout << sol.countGoodStrings(low, high, zero, one) << endl;
  return 0;
}