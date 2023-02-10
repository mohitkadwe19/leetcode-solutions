#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  const int dx[4] = {-1, 1, 0, 0};
  const int dy[4] = {0, 0, -1, 1};

  int maxDistance(vector<vector<int>> &grid)
  {
    int r = grid.size();
    int c = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < r; ++i) // storing ones into queue
    {
      for (int j = 0; j < c; ++j)
      {
        if (grid[i][j] == 1)
        {
          q.push({i, j});
          grid[i][j] = 2;
        }
      }
    }
    if (q.empty() || q.size() == r * c)
      return -1; // if all 1 or all zero returning -1
    int cnt = 0;
    int maxi = 0;
    while (!q.empty())
    {
      int sz = q.size();
      while (sz--)
      {
        auto node = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
          int next_i = node.first + dx[i];
          int next_j = node.second + dy[i];
          if (next_i >= 0 && next_j >= 0 && next_i < r && next_j < c)
          {
            if (grid[next_i][next_j] == 0)
            {
              grid[next_i][next_j] = 2; // make it visited by marking it to 2.
              q.push({next_i, next_j});
            }
          }
        }
      }
      maxi++;
    }
    return maxi - 1; // we do it because it also count itself
  }
};

int main()
{
  Solution s;
  vector<vector<int>> grid = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
  cout << s.maxDistance(grid) << endl;
  return 0;
}