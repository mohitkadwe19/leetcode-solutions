#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int threeSumClosest(vector<int> &nums, int target)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n; i++)
    {
      int j = i + 1;
      int k = n - 1;
      while (j < k)
      {
        int sum = nums[i] + nums[j] + nums[k];
        if (abs(target - sum) < abs(target - ans))
        {
          ans = sum;
        }
        if (sum > target)
        {
          k--;
        }
        else
        {
          j++;
        }
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {-1, 2, 1, -4};
  int target = 1;
  cout << s.threeSumClosest(nums, target) << endl;
  return 0;
}