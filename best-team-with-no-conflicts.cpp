#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int bestTeamScore(vector<int> &scores, vector<int> &ages)
  {
    int n = scores.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
      v.push_back({ages[i], scores[i]});
    }
    sort(v.begin(), v.end());
    vector<int> dp(n, 0);
    dp[0] = v[0].second;
    int ans = dp[0];
    for (int i = 1; i < n; i++)
    {
      dp[i] = v[i].second;
      for (int j = 0; j < i; j++)
      {
        if (v[j].second <= v[i].second)
        {
          dp[i] = max(dp[i], dp[j] + v[i].second);
        }
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> scores = {1, 3, 5, 10, 15};
  vector<int> ages = {1, 2, 3, 4, 5};
  cout << s.bestTeamScore(scores, ages) << endl;
  return 0;
}