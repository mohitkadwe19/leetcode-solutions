#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isBipartite(vector<vector<int>> &graph)
  {
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
      if (color[i] == -1)
      {
        queue<int> q;
        q.push(i);
        color[i] = 0;
        while (!q.empty())
        {
          int node = q.front();
          q.pop();
          for (int nbr : graph[node])
          {
            if (color[nbr] == -1)
            {
              color[nbr] = 1 - color[node];
              q.push(nbr);
            }
            else if (color[nbr] == color[node])
              return false;
          }
        }
      }
    }
    return true;
  }
};

int main()
{
  vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  Solution sol;
  cout << sol.isBipartite(graph) << endl;
  return 0;
}