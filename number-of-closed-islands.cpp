#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(vector<vector<int>> &gr, int i, int j)
  {
    if (i == gr.size() || j == gr[0].size() || j < 0 || i < 0)
      return;
    if (gr[i][j] == 1)
      return;
    gr[i][j] = 1;
    dfs(gr, i + 1, j);
    dfs(gr, i - 1, j);
    dfs(gr, i, j - 1);
    dfs(gr, i, j + 1);
  }

  int closedIsland(vector<vector<int>> &gr)
  {
    int n = gr.size();
    int m = gr[0].size();
    for (int i = 0; i < n; i++)
    {
      if (gr[i][0] == 0)
      {
        dfs(gr, i, 0);
      }
      if (gr[i][m - 1] == 0)
      {
        dfs(gr, i, m - 1);
      }
    }
    for (int i = 0; i < m; i++)
    {
      if (gr[0][i] == 0)
      {
        dfs(gr, 0, i);
      }
      if (gr[n - 1][i] == 0)
      {
        dfs(gr, n - 1, i);
      }
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (gr[i][j] == 0)
        {
          c++;
          dfs(gr, i, j);
        }
      }
    }
    return c;
  }
};

int main()
{
  vector<vector<int>> grid = {{1, 1, 1, 1, 1, 1, 1, 0},
                              {1, 0, 0, 0, 0, 1, 1, 0},
                              {1, 0, 1, 0, 1, 1, 1, 0},
                              {1, 0, 0, 0, 0, 1, 0, 1},
                              {1, 1, 1, 1, 1, 1, 1, 0}};
  Solution s;
  cout << s.closedIsland(grid) << endl;
  return 0;
}