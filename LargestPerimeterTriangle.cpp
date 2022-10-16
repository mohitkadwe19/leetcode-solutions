#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int largestPerimeter(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 1; i >= 2; i--)
    {
      if (nums[i] < nums[i - 1] + nums[i - 2])
      {
        return nums[i] + nums[i - 1] + nums[i - 2];
      }
    }
    return 0;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {2, 1, 2};
  cout << s.largestPerimeter(nums) << endl;
  return 0;
}