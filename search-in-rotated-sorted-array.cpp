#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int find(vector<int> &nums)
  {

    int l = 0, r = nums.size() - 1;
    int n = nums.size() - 1;
    int ans = 0;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      if (nums[mid] > nums[n])
      {
        l = mid + 1;
      }
      else
      {
        ans = mid;
        r = mid - 1;
      }
    }

    return ans;
  }

  int findTargetValue(vector<int> &nums, int target, int l, int r)
  {

    while (l <= r)
    {

      int mid = l + (r - l) / 2;
      if (nums[mid] == target)
        return mid;

      if (nums[mid] > target)
      {
        r = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }

    return -1;
  }
  int search(vector<int> &nums, int target)
  {

    int p = find(nums);
    int idx = findTargetValue(nums, target, 0, p - 1);
    cout << p;
    if (idx != -1)
      return idx;

    return findTargetValue(nums, target, p, nums.size() - 1);
  }
};

int main()
{
  Solution s;
  vector<int> res = {4, 5, 6, 7, 0, 1, 2};
  cout << s.search(res, 0) << endl;
  return 0;
}