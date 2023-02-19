#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
  {
    map<int, int> mp;
    vector<vector<int>> ans;
    for (auto it : nums1)
    {
      mp[it[0]] += it[1];
    }
    for (auto it : nums2)
    {
      mp[it[0]] += it[1];
    }
    for (auto it : mp)
    {
      ans.push_back({it.first, it.second});
    }
    return ans;
  }
};

int main()
{
  vector<vector<int>> nums1 = {{1, 3}, {5, 2}, {1, 6}};
  vector<vector<int>> nums2 = {{0, 3}, {4, 1}};
  vector<vector<int>> ans = Solution().mergeArrays(nums1, nums2);
  for (auto row : ans)
  {
    for (auto num : row)
    {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}