#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
  {
    vector<int> ans;
    vector<int> dp;
    for (int i = 0; i < obstacles.size(); i++)
    {
      int idx = upper_bound(dp.begin(), dp.end(), obstacles[i]) - dp.begin();
      if (idx == dp.size())
        dp.push_back(obstacles[i]);
      else
        dp[idx] = obstacles[i];
      ans.push_back(idx + 1);
    }
    return ans;
  }
};

int main()
{
  vector<int> shortestObstacleCourseAtEachPosition = {1, 2, 3, 2};
  Solution sol;
  vector<int> ans = sol.longestObstacleCourseAtEachPosition(shortestObstacleCourseAtEachPosition);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}