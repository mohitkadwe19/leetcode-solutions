#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findMaxK(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int i = 0, j = n - 1;
    while (j > 0)
    {
      for (i = 0; i < n; i++)
      {
        if (abs(nums[i]) == nums[j] && nums[i] != nums[j])
        {
          return nums[j];
        }
      }
      j--;
    }
    return -1;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {-1, 2, -3, 3};
  cout << sol.findMaxK(nums) << endl;
  return 0;
}