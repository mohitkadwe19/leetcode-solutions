#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
  {
    vector<int> red[n], blue[n];
    for (auto it : redEdges)
    {
      red[it[0]].push_back(it[1]);
    }
    for (auto it : blueEdges)
    {
      blue[it[0]].push_back(it[1]);
    }

    queue<int> q;
    q.push(0);
    vector<int> rdis(n, 1e9), bdis(n, 1e9);

    rdis[0] = 0;
    bdis[0] = 0;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      if (rdis[node] != 1e9)
      {
        for (auto it : blue[node])
        {
          if (bdis[it] > rdis[node] + 1)
          {
            bdis[it] = rdis[node] + 1;
            q.push(it);
          }
        }
      }
      if (bdis[node] != 1e9)
      {
        for (auto it : red[node])
        {
          if (rdis[it] > bdis[node] + 1)
          {
            rdis[it] = bdis[node] + 1;
            q.push(it);
          }
        }
      }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
      ans[i] = min(rdis[i], bdis[i]);
      if (ans[i] == 1e9)
        ans[i] = -1;
    }
    return ans;
  }
};

int main()
{
  int n = 3;
  vector<vector<int>> redEdges = {{0, 1}, {1, 2}};
  vector<vector<int>> blueEdges = {};
  Solution s;
  vector<int> ans = s.shortestAlternatingPaths(n, redEdges, blueEdges);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}