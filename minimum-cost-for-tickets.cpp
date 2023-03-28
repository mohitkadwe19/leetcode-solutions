#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int mincostTickets(vector<int> &days, vector<int> &costs)
  {
    int n = days.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
      int j = i;
      dp[i] = dp[i + 1] + costs[0];
      while (j < n && days[j] - days[i] < 7)
        j++;
      dp[i] = min(dp[i], dp[j] + costs[1]);
      while (j < n && days[j] - days[i] < 30)
        j++;
      dp[i] = min(dp[i], dp[j] + costs[2]);
    }
    return dp[0];
  }
};

int main()
{
  Solution s;
  vector<int> days = {1, 4, 6, 7, 8, 20};
  vector<int> costs = {2, 7, 15};
  cout << s.mincostTickets(days, costs) << endl;
  return 0;
}