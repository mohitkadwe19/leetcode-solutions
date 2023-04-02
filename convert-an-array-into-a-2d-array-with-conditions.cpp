#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> findMatrix(vector<int> &nums)
  {
    map<int, int> mp;
    for (auto i : nums)
    {
      mp[i]++;
    }
    int maxNum = 0;
    for (auto i : mp)
    {
      if (i.second > maxNum)
      {
        maxNum = i.second;
      }
    }
    vector<vector<int>> ans(maxNum);
    for (int i = 0; i < maxNum; i++)
    {
      for (auto j : mp)
      {
        if (j.second > 0)
        {
          ans[i].push_back(j.first);
          mp[j.first]--;
        }
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<vector<int>> ans = s.findMatrix(nums);
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