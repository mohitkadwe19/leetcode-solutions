#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestSubArray(vector<int> &nums)
  {
    int n = nums.size();
    int maxNum = INT_MIN;
    int frequency = 1, ans = 0;
    for (int i = 0; i < n; ++i)
    {
      maxNum = max(maxNum, nums[i]);
    }
    for (int i = 1; i < n; ++i)
    {
      if (nums[i] == nums[i - 1] && nums[i] == maxNum)
      {
        frequency++;
      }
      else
      {
        ans = max(ans, frequency);
        frequency = 1;
      }
    }
    ans = max(ans, frequency);
    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3, 3, 2, 2};
  cout << sol.longestSubArray(nums) << endl;
  return 0;
}