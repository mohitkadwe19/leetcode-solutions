#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int arr1[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
  int arr2[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

  bool checkValidGrid(vector<vector<int>> &grid)
  {
    queue<pair<int, int>> q;
    int n = grid.size(), m = grid[0].size(), k = 0;
    q.push({0, 0});

    while (!q.empty())
    {
      int count = 0;
      int x = q.front().first, y = q.front().second;
      q.pop();

      for (int i = 0; i < 8; i++)
      {
        int nx = x + arr1[i], ny = y + arr2[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == k + 1)
        {
          x = nx, y = ny;
          count = 1;
          break;
        }
      }

      if (count)
      {
        q.push({x, y});
      }
      k++;
    }

    return k == (n * m) ? 1 : 0;
  }
};

int main()
{
  vector<vector<int>> grid = {{0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0}};
  Solution s;
  bool res = s.checkValidGrid(grid);
  cout << res << endl;
  return 0;
}