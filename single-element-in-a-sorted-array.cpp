#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int singleNonDuplicate(vector<int> &nums)
  {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l < r)
    {
      int mid = l + (r - l) / 2;
      if (mid % 2 == 1)
      {
        mid--;
      }
      if (nums[mid] == nums[mid + 1])
      {
        l = mid + 2;
      }
      else
      {
        r = mid;
      }
    }
    return nums[l];
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
  cout << s.singleNonDuplicate(nums) << endl;
  return 0;
}