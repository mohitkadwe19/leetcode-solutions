#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int thirdMax(vector<int> &nums)
  {
    long max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
      if (max1 == nums[i] || max2 == nums[i] || max3 == nums[i])
      {
        continue;
      }
      if (max1 < nums[i])
      {
        if (max2 < nums[i])
        {
          if (max3 < nums[i])
          {
            max1 = max2;
            max2 = max3;
            max3 = nums[i];
          }
          else
          {
            max1 = max2;
            max2 = nums[i];
          }
        }
        else
        {
          max1 = nums[i];
        }
      }
    }
    if (max1 > LONG_MIN)
    {
      return max1;
    }
    else
    {
      return max3;
    }
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 1};
  cout << s.thirdMax(nums) << endl;
  return 0;
}