#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int helper(vector<int> &locations, int start, int finish, int fuel, vector<vector<int>> &dp)
  {
    int n = locations.size();
    if (fuel < 0)
      return 0;
    if (dp[start][fuel] != -1)
      return dp[start][fuel];
    int ans = 0;
    if (start == finish)
      ans++;
    for (int i = 0; i < n; i++)
    {
      if (i != start)
      {
        ans = (ans + helper(locations, i, finish, fuel - abs(locations[i] - locations[start]), dp)) % 1000000007;
      }
    }
    return dp[start][fuel] = ans;
  }
  int countRoutes(vector<int> &locations, int start, int finish, int fuel)
  {
    int n = locations.size();
    vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));
    return helper(locations, start, finish, fuel, dp);
  }
};

int main()
{
  Solution s;
  vector<int> locations = {2, 3, 6, 8, 4};
  int start = 1, finish = 3, fuel = 5;
  cout << s.countRoutes(locations, start, finish, fuel) << endl;
  return 0;
}