#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void backtrack(vector<vector<int>> &ans, vector<int> &temp, int n, int k, int start)
  {
    if (temp.size() == k)
    {
      ans.push_back(temp);
      return;
    }
    for (int i = start; i <= n; i++)
    {
      temp.push_back(i);
      backtrack(ans, temp, n, k, i + 1);
      temp.pop_back();
    }
  }
  vector<vector<int>> combine(int n, int k)
  {

    vector<vector<int>> ans;
    vector<int> temp;
    backtrack(ans, temp, n, k, 1);
    return ans;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> ans = s.combine(4, 2);
  for (auto i : ans)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}