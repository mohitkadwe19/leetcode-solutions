#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(int s, int n, vector<vector<int>> &isConnected, vector<bool> &visited)
  {

    // s=1
    // 0 1 2 3 4 -- index
    // 1 2 3 4 5 -- city
    // 1 1 0 1 0 -- visited

    visited[s] = true;
    vector<int> adj;
    for (int j = 0; j < n; j++)
    {
      int x = isConnected[s][j]; // x = connection
      if (x == 1)
      {
        adj.push_back(j);
      }
    }
    for (auto x : adj)
    {
      if (!visited[x])
      {
        dfs(x, n, isConnected, visited);
      }
    }
  }
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        count++;
        dfs(i, n, isConnected, visited);
      }
    }
    return count;
  }
};

int main()
{
  vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  Solution s;
  cout << s.findCircleNum(isConnected) << endl;
  return 0;
}