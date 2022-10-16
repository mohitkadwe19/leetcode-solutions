#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxSum(vector<vector<int>> &grid)
  {
    int maxSum = INT_MIN;
    for (int i = 0; i < grid.size() - 2; i++)
    {
      for (int j = 0; j < grid[0].size() - 2; j++)
      {
        int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
        maxSum = max(maxSum, sum);
      }
    }
    return maxSum;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> grid = {{6, 2, 1, 3},
                              {4, 2, 1, 5},
                              {9, 2, 8, 7},
                              {4, 1, 2, 9}};
  cout << s.maxSum(grid) << endl;
  return 0;
}