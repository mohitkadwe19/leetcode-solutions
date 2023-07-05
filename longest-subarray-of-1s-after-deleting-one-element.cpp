#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestSubarray(vector<int> &nums)
  {
    int n = nums.size();
    int left = 0, right = 0, ans = 0, count = 0;
    while (right < n)
    {
      if (nums[right] == 0)
        count++;
      while (count > 1)
      {
        if (nums[left] == 0)
          count--;
        left++;
      }
      ans = max(ans, right - left);
      right++;
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 1, 0, 1};
  cout << sol.longestSubarray(nums) << endl;
  return 0;
}