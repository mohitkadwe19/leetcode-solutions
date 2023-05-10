#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> generateMatrix(int n)
  {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int i = 0, j = 0, k = 1;
    while (k <= n * n)
    {
      while (j < n && ans[i][j] == 0)
        ans[i][j++] = k++;
      j--;
      i++;
      while (i < n && ans[i][j] == 0)
        ans[i++][j] = k++;
      i--;
      j--;
      while (j >= 0 && ans[i][j] == 0)
        ans[i][j--] = k++;
      j++;
      i--;
      while (i >= 0 && ans[i][j] == 0)
        ans[i--][j] = k++;
      i++;
      j++;
    }
    return ans;
  }
};

int main()
{
  int n = 3;
  Solution sol;
  vector<vector<int>> ans = sol.generateMatrix(n);
  for (auto i : ans)
  {
    for (auto j : i)
      cout << j << " ";
    cout << endl;
  }
  return 0;
}