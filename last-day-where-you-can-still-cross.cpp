#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int latestDayToCross(int row, int col, vector<vector<int>> &cells)
  {
    int l = 0, r = cells.size(), latestDay = 0;
    while (l < r)
    {
      int m = (l + r) / 2;
      if (m == l)
        break;
      if (cross(row, col, cells, m))
      {
        l = m;
        latestDay = m;
      }
      else
        r = m;
    }
    return latestDay;
  }
  bool cross(int row, int col, vector<vector<int>> &cells, int idx)
  {
    vector<vector<int>> area(row + 1, vector<int>(col + 2, 0));
    for (int i = 1; i <= row; i++)
      for (int j = 1; j <= col; j++)
        area[i][j] = 1;
    for (int i = 0; i < idx; i++)
      area[cells[i][0]][cells[i][1]] = 0;

    vector<vector<bool>> visited(row + 1, vector<bool>(col + 2, false));
    queue<vector<int>> que;
    for (int c = 1; c <= col; c++)
      if (area[1][c] == 1)
      {
        visited[1][c] = true;
        que.push(vector<int>{1, c});
      }
    while (!que.empty())
    {
      int n = que.size();
      for (int i = 0; i < n; i++)
      {
        vector<int> cell = que.front();
        que.pop();
        if (cell[0] == row)
          return true;
        pushCell(que, area, visited, cell[0] - 1, cell[1]);
        pushCell(que, area, visited, cell[0] + 1, cell[1]);
        pushCell(que, area, visited, cell[0], cell[1] - 1);
        pushCell(que, area, visited, cell[0], cell[1] + 1);
      }
    }
    return false;
  }
  void pushCell(queue<vector<int>> &que, vector<vector<int>> &area, vector<vector<bool>> &visited, int row, int col)
  {
    if (area[row][col] && !visited[row][col])
    {
      visited[row][col] = true;
      que.push(vector<int>{row, col});
    }
  }
};

int main()
{
  Solution s;
  vector<vector<int>> cells = {{1, 1}, {2, 1}, {1, 2}, {2, 2}};
  cout << s.latestDayToCross(2, 2, cells) << endl;
  return 0;
}