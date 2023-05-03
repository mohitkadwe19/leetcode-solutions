#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
  {
    vector<vector<int>> ans = {{}, {}};
    set<int> s1(nums1.begin(), nums1.end());
    set<int> s2(nums2.begin(), nums2.end());

    for (auto x : s1)
    {
      if (s2.count(x) == 0)
        ans[0].push_back(x);
    }
    for (auto x : s2)
    {
      if (s1.count(x) == 0)
        ans[1].push_back(x);
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> nums1 = {1, 2, 3, 4, 5};
  vector<int> nums2 = {1, 2, 3, 4, 5};
  vector<vector<int>> ans = sol.findDifference(nums1, nums2);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}