#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> groupThePeople(vector<int> &groupSizes)
  {
    unordered_map<int, vector<int>> u;
    for (int i = 0; i < groupSizes.size(); i++)
    {
      u[groupSizes[i]].push_back(i);
    }
    vector<vector<int>> v;
    for (auto x : u)
    {
      int k = x.first;
      vector<int> f = x.second;
      int c = f.size() / k;
      int l = 0;
      for (int i = 0; i < c; i++)
      {
        vector<int> ans;
        for (int j = 0; j < k; j++)
        {
          ans.push_back(f[l]);
          l++;
        }
        v.push_back(ans);
      }
    }
    return v;
  }
};

int main()
{
  vector<int> groupSizes = {3, 3, 3, 3, 3, 1, 3};
  Solution s;
  vector<vector<int>> ans = s.groupThePeople(groupSizes);
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