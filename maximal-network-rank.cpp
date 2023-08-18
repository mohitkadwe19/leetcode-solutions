#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximalNetworkRank(int n, vector<vector<int>> &roads)
  {
    vector<int> adj[n];
    vector<vector<int>> link(n, vector<int>(n, 0));
    for (int i = 0; i < roads.size(); i++)
    {
      int u = roads[i][0];
      int v = roads[i][1];
      adj[u].push_back(v);
      adj[v].push_back(u);
      link[u][v] = 1;
      link[v][u] = 1;
    }

    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == j)
          continue;
        int cnt = adj[i].size() + adj[j].size();
        if (link[i][j] == 1 && cnt > maxi)
          maxi = cnt - 1;
        else if (link[i][j] != 1 && cnt > maxi)
          maxi = cnt;
      }
    }
    return maxi;
  }
};

int main()
{
  Solution s;
  int n = 3;
  vector<vector<int>> roads = {{2, 5}, {7, 2}, {5, 1}};
  cout << s.maximalNetworkRank(n, roads);
  return 0;
}