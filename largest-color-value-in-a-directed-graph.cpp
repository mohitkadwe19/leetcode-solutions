#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int largestPathValue(string colors, vector<vector<int>> &edges)
  {
    int n = colors.size();
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);
    for (auto &edge : edges)
    {
      graph[edge[0]].push_back(edge[1]);
      indegree[edge[1]]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
      if (indegree[i] == 0)
        q.push(i);
    }
    vector<int> colorCount(n, 0);
    vector<vector<int>> dp(n, vector<int>(26, 0));
    int count = 0;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      count++;
      colorCount[node]++;
      dp[node][colors[node] - 'a']++;
      for (int i = 0; i < 26; i++)
      {
        dp[node][i] = max(dp[node][i], dp[node][i] + colorCount[node] - 1);
      }
      for (auto &child : graph[node])
      {
        indegree[child]--;
        if (indegree[child] == 0)
          q.push(child);
        for (int i = 0; i < 26; i++)
        {
          dp[child][i] = max(dp[child][i], dp[node][i]);
        }
      }
    }
    if (count != n)
      return -1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < 26; j++)
      {
        ans = max(ans, dp[i][j]);
      }
    }
    return ans;
  }
};

int main()
{
  string colors = "abaca";
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {3, 4}};
  Solution obj;
  cout << obj.largestPathValue(colors, edges) << endl;
  return 0;
}