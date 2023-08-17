#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dr[4] = {0, 0, 1, -1};
  int dc[4] = {1, -1, 0, 0};
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
  {
    int m = mat.size();
    int n = mat[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> dist(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        dist[i][j] = INT_MAX;
        if (mat[i][j] == 0)
        {
          q.push({i, j});
          dist[i][j] = 0;
        }
      }
    }
    while (!q.empty())
    {
      int row = q.front().first;
      int col = q.front().second;

      q.pop();

      for (int i = 0; i < 4; i++)
      {
        int next_row = row + dr[i];
        int next_col = col + dc[i];
        if (next_row >= 0 && next_row < m && next_col >= 0 && next_col < n)
        {
          if (dist[next_row][next_col] > dist[row][col] + 1)
          {
            dist[next_row][next_col] = dist[row][col] + 1;
            q.push({next_row, next_col});
          }
        }
      }
    }
    return dist;
  }
};

int main()
{
  Solution obj;
  vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  vector<vector<int>> ans = obj.updateMatrix(mat);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[0].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}