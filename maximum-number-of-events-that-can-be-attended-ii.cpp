#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int finder(vector<vector<int>> &events, vector<int> &inv)
  {
    int i = 0, j = events.size() - 1;
    int ansIdx = events.size();

    while (i <= j)
    {
      int mid = i + (j - i) / 2;

      if (events[mid][0] > inv[1])
      {
        ansIdx = mid;
        j = mid - 1;
      }
      else
      {
        i = mid + 1;
      }
    }

    return ansIdx;
  }
  int helper(vector<vector<int>> &events, int i, int k, vector<vector<int>> &dp)
  {

    if (i == events.size() || k == 0)
      return 0;

    if (dp[i][k] != -1)
      return dp[i][k];

    int max1 = INT_MIN, max2 = INT_MIN;

    int idx = finder(events, events[i]);

    max1 = events[i][2] + helper(events, idx, k - 1, dp);
    max2 = helper(events, i + 1, k, dp);

    return dp[i][k] = max(max1, max2);
  }
  int maxValue(vector<vector<int>> &events, int k)
  {
    sort(events.begin(), events.end());
    vector<vector<int>> dp(events.size() + 1, vector<int>(k + 1, -1));
    return helper(events, 0, k, dp);
  }
};

int main()
{
  vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  int k = 2;
  Solution s;
  cout << s.maxValue(events, k);
  return 0;
}