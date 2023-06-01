#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid)
  {
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
      return -1;
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    int ans = 0;
    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        auto curr = q.front();
        q.pop();
        int i = curr.first;
        int j = curr.second;
        if (i == n - 1 && j == n - 1)
          return ans + 1;
        for (auto d : dir)
        {
          int x = i + d[0];
          int y = j + d[1];
          if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0)
          {
            q.push({x, y});
            grid[x][y] = 1;
          }
        }
      }
      ans++;
    }
    return -1;
  }
};

int main()
{
  vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  Solution sol;
  cout << sol.shortestPathBinaryMatrix(grid) << endl;
  return 0;
}