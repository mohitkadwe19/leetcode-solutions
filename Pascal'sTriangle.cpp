#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> res;
    if (numRows == 0)
      return res;
    res.push_back(vector<int>(1, 1));
    if (numRows == 1)
      return res;
    res.push_back(vector<int>(2, 1));
    if (numRows == 2)
      return res;
    for (int i = 2; i < numRows; i++)
    {
      vector<int> tmp(i + 1, 1);
      for (int j = 1; j < i; j++)
      {
        tmp[j] = res[i - 1][j - 1] + res[i - 1][j];
      }
      res.push_back(tmp);
    }
    return res;
  }
};

int main()
{
  Solution s;
  int numRows = 5;
  vector<vector<int>> result = s.generate(numRows);
  for (int i = 0; i < result.size(); i++)
  {
    for (int j = 0; j < result[i].size(); j++)
    {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
