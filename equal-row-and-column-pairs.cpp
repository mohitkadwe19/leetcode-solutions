#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int equalPairs(vector<vector<int>> &grid)
  {
    int count = 0;

    int n = grid.size();

    for (int i = 0; i < n; i++)
    {

      for (int j = 0; j < n; j++)
      {
        bool match = true;

        for (int k = 0; k < n; k++)
        {
          if (grid[i][k] != grid[k][j])
          {

            match = false;
            break;
          }
        }

        count += match ? 1 : 0;
      }
    }

    return count;
  }
};

int main()
{
  Solution obj;
  vector<vector<int>> grid = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 2}};
  cout << obj.equalPairs(grid);
  return 0;
}