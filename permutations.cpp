#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void helper(vector<int> &nums, vector<vector<int>> &res, int ind)
  {
    int n = nums.size();
    if (ind == n)
    {
      res.push_back(nums);
      return;
    }
    for (int i = ind; i < n; i++)
    {
      swap(nums[ind], nums[i]);
      helper(nums, res, ind + 1);
      swap(nums[ind], nums[i]);
    }
    return;
  }

  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<vector<int>> res;
    helper(nums, res, 0);
    return res;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> ans = sol.permute(nums);
  for (auto &v : ans)
  {
    for (auto &i : v)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}