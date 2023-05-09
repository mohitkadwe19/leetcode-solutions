#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix)
  {
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();
    int count = 0;
    int total = row * col;

    int startingrow = 0;
    int startingcol = 0;
    int endingrow = row - 1;
    int endingcol = col - 1;

    while (count < total)
    {
      for (int i = startingcol; count < total && i <= endingcol; i++)
      {
        ans.push_back(matrix[startingrow][i]);
        count++;
      }
      startingrow++;

      for (int i = startingrow; count < total && i <= endingrow; i++)
      {
        ans.push_back(matrix[i][endingcol]);
        count++;
      }
      endingcol--;

      for (int i = endingcol; count < total && i >= startingcol; i--)
      {
        ans.push_back(matrix[endingrow][i]);
        count++;
      }
      endingrow--;

      for (int i = endingrow; count < total && i >= startingrow; i--)
      {
        ans.push_back(matrix[i][startingcol]);
        count++;
      }
      startingcol++;
    }

    return ans;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> ans = s.spiralOrder(matrix);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}