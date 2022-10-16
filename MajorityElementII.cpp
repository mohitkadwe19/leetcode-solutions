#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    int n = nums.size();
    int acc = n / 3;
    vector<int> ans;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
      mp[nums[i]]++;
    }

    for (auto x : mp)
    {
      if (x.second > acc)
      {
        ans.push_back(x.first);
      }
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {3, 2, 3};
  vector<int> ans = sol.majorityElement(nums);

  for (auto x : ans)
  {
    cout << x << " ";
  }
  return 0;
}