#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int searchInsert(vector<int> &nums, int target)
  {
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return l;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 3, 5, 6};
  int target = 5;
  cout << s.searchInsert(nums, target) << endl;
  return 0;
}