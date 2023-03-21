#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long zeroFilledSubarray(vector<int> &nums)
  {
    long long ans = 0, c = 0;
    for (int i = 0; i <= nums.size(); i++)
    {
      if (i < nums.size() && nums[i] == 0)
        c++;
      else if (c != 0)
      {
        ans += (c * (c + 1) / 2);
        c = 0;
      }
    }
    return ans;
  }
};

int main()
{
  vector<int> nums = {1, 3, 0, 0, 2, 0, 0, 4};
  Solution solution;
  cout << solution.zeroFilledSubarray(nums) << endl;
  return 0;
}