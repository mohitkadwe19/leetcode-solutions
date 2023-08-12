#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {

    int maxRow = obstacleGrid.size();
    int maxCol = obstacleGrid[0].size();
    obstacleGrid[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;

    // there is only one way to travel in first row
    for (int col = 1; col < obstacleGrid[0].size(); col++)
    {
      if (obstacleGrid[0][col] == 1)
        obstacleGrid[0][col] = 0;
      else
        obstacleGrid[0][col] = obstacleGrid[0][col - 1];
    }

    // there is only one way to traverse through 1st column
    for (int row = 1; row < obstacleGrid.size(); row++)
    {
      if (obstacleGrid[row][0] == 1)
        obstacleGrid[row][0] = 0;
      else
        obstacleGrid[row][0] = obstacleGrid[row - 1][0];
    }

    for (int row = 1; row < obstacleGrid.size(); row++)
    {
      for (int col = 1; col < obstacleGrid[0].size(); col++)
      {
        if (obstacleGrid[row][col] == 1)
          obstacleGrid[row][col] = 0;
        else
          obstacleGrid[row][col] =
              obstacleGrid[row][col - 1] + obstacleGrid[row - 1][col];
      }
    }
    return obstacleGrid[maxRow - 1][maxCol - 1];
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
  return 0;
}