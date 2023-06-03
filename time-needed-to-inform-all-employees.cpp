#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
  {
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
      if (manager[i] != -1)
        adj[manager[i]].push_back(i);
    }
    queue<pair<int, int>> q;
    q.push({headID, 0});
    int ans = 0;
    while (!q.empty())
    {
      int node = q.front().first;
      int time = q.front().second;
      q.pop();
      ans = max(ans, time);
      for (int i = 0; i < adj[node].size(); i++)
      {
        q.push({adj[node][i], time + informTime[node]});
      }
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> manager = {2, 2, -1, 2, 2, 2};
  vector<int> informTime = {0, 0, 1, 0, 0, 0};
  cout << sol.numOfMinutes(6, 2, manager, informTime) << endl;
  return 0;
}