#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minSubArrayLen(int target, vector<int> &nums)
  {
    int n = nums.size();
    int ans = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += nums[i];
      while (sum >= target)
      {
        ans = min(ans, i + 1 - left);
        sum -= nums[left++];
      }
    }
    return ans != INT_MAX ? ans : 0;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int target = 7;
  cout << sol.minSubArrayLen(target, nums) << endl;
  return 0;
}