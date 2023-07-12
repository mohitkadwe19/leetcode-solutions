#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool dfs(vector<vector<int>> &graph, int src, vector<int> &safe)
  {
    if (safe[src] != -1)
    {
      return safe[src];
    }

    safe[src] = 0;
    for (int x : graph[src])
    {
      if (!dfs(graph, x, safe))
      {
        return false;
      }
    }

    safe[src] = 1;
    return true;
  }

  vector<int> eventualSafeNodes(vector<vector<int>> &graph)
  {
    int n = graph.size();
    vector<int> safe(n, -1);

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
      if (dfs(graph, i, safe))
      {
        ans.push_back(i);
      }
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  int n = 3;
  vector<vector<int>> graph = {{1, 2}, {2, 0}, {0, 1}};
  vector<int> ans = sol.eventualSafeNodes(graph);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return 0;
}