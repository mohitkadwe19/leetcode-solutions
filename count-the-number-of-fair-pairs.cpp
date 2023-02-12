#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper)
  {
    sort(nums.begin(), nums.end());
    long long ans = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
      int j = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
      int k = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin() - 1;
      if (j <= k)
      {
        ans += k - j + 1;
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {0, 1, 7, 4, 4, 5};
  int lower = 3, upper = 6;
  cout << s.countFairPairs(nums, lower, upper) << endl;
  return 0;
}