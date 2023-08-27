#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool fun(int curr, int prev, vector<vector<int>> &dp, unordered_map<int, int> &m, vector<int> &stones)
  {
    if (curr == stones.size() - 1)
      return true;
    if (dp[curr][prev] != -1)
      return dp[curr][prev];
    int jump = stones[curr] - stones[prev];
    bool check = false;
    if (jump > 1 && m.find(stones[curr] + jump - 1) != m.end())
      check = check || fun(m[stones[curr] + jump - 1], curr, dp, m, stones);
    if (m.find(stones[curr] + jump) != m.end())
      check = check || fun(m[stones[curr] + jump], curr, dp, m, stones);
    if (m.find(stones[curr] + jump + 1) != m.end())
      check = check || fun(m[stones[curr] + jump + 1], curr, dp, m, stones);
    return dp[curr][prev] = check;
  }

public:
  bool canCross(vector<int> &stones)
  {
    if (stones[1] - stones[0] > 1)
      return false;
    int n = stones.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
      m[stones[i]] = i;
    }
    return fun(1, 0, dp, m, stones);
  }
};

int main()
{
  vector<int> stones = {1, 2, 1};
  Solution s;
  cout << s.canCross(stones) << endl;
  return 0;
}