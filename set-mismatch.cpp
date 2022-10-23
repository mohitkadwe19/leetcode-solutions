#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findErrorNums(vector<int> &nums)
  {
    unordered_set<int> s;
    int sum = nums.size() * (nums.size() + 1) / 2;
    int target = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      sum -= nums[i];
      s.insert(nums[i]);

      if (!target && s.size() == i)
      {
        target = nums[i];
      }
    }

    return {target, (target + sum)};
  }
};

int main()
{
  Solution s;
  vector<int> nums = {2, 2};
  vector<int> ans = s.findErrorNums(nums);
  for (int i : ans)
    cout << i << " ";
  return 0;
}