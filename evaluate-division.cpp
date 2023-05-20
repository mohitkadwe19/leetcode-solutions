#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double dfs(unordered_map<string, unordered_map<string, double>> &graph, string a, string b, unordered_set<string> &visited)
  {
    if (a == b)
      return 1.0;
    visited.insert(a);
    for (auto x : graph[a])
    {
      if (visited.find(x.first) != visited.end())
        continue;
      double val = dfs(graph, x.first, b, visited);
      if (val != -1.0)
        return val * x.second;
    }
    return -1.0;
  }
  vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
  {
    unordered_map<string, unordered_map<string, double>> graph;
    for (int i = 0; i < equations.size(); i++)
    {
      string a = equations[i][0];
      string b = equations[i][1];
      double val = values[i];
      graph[a][b] = val;
      graph[b][a] = 1 / val;
    }
    vector<double> ans;
    for (auto q : queries)
    {
      string a = q[0];
      string b = q[1];
      if (graph.find(a) == graph.end() || graph.find(b) == graph.end())
      {
        ans.push_back(-1.0);
        continue;
      }
      unordered_set<string> visited;
      double val = dfs(graph, a, b, visited);
      ans.push_back(val);
    }
    return ans;
  }
};

int main()
{
  vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
  vector<double> values = {2.0, 3.0};
  vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
  Solution sol;
  vector<double> ans = sol.calcEquation(equations, values, queries);
  for (auto x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}