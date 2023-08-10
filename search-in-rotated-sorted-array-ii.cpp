#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool search(vector<int> &nums, int target)
  {
    sort(nums.begin(), nums.end());

    int start = 0, end = nums.size() - 1, mid;
    while (start <= end)
    {
      mid = start + (end - start) / 2;

      if (nums[mid] == target)
      {
        return true;
      }
      else if (nums[mid] > target)
      {
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }
    return false;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
  int target = 0;
  cout << sol.search(nums, target) << endl;
  return 0;
}