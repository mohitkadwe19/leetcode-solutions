#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target)
      {
        return mid;
      }
      else if (nums[mid] < target)
      {
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }
    return -1;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int target = 5;
  cout << s.search(nums, target) << endl;
  return 0;
}