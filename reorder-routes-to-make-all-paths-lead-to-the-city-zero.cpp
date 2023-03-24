#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minReorder(int n, vector<vector<int>> &connections)
  {
    vector<vector<int>> graph(n);
    for (auto &c : connections)
    {
      graph[c[0]].push_back(c[1]);
      graph[c[1]].push_back(-c[0]);
    }
    int ans = 0;
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      for (int v : graph[u])
      {
        if (v < 0)
        {
          v = -v;
          if (!visited[v])
          {
            visited[v] = true;
            q.push(v);
          }
        }
        else
        {
          if (!visited[v])
          {
            visited[v] = true;
            q.push(v);
            ans++;
          }
        }
      }
    }
    return ans;
  }
};

int main()
{
  int n = 6;
  vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
  Solution s;
  cout << s.minReorder(n, connections) << endl;
  return 0;
}