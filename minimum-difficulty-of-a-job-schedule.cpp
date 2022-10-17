#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int day, int index, vector<int> &jobs, vector<vector<int>> &dp)
  {
    if (day < 0)
      return 1e7;

    if (index >= jobs.size())
    {
      if (day > 0)
        return 1e7;

      return 0;
    }

    if (dp[day][index] != -1)
      return dp[day][index];

    int diff = jobs[index];
    int val = INT_MAX;

    for (int i = index; i < jobs.size(); i++)
    {
      diff = max(diff, jobs[i]);
      val = min(val, diff + solve(day - 1, i + 1, jobs, dp));
    }
    return dp[day][index] = val;
  }
  int minDifficulty(vector<int> &jobDifficulty, int d)
  {
    int n = jobDifficulty.size();

    vector<vector<int>> dp(d + 1, vector<int>(n + 1, -1));
    int ans = solve(d, 0, jobDifficulty, dp);
    if (ans >= 10000007)
      return -1;

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> jobDifficulty = {6, 5, 4, 3, 2, 1};
  int d = 2;
  cout << s.minDifficulty(jobDifficulty, d) << endl;
  return 0;
}