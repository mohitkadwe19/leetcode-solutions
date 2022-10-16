#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 0)
    {
      return 0;
    }
    else
    {
      int sum = 0;
      for (int i = 0; i < n; i++)
      {
        sum += nums[i];
      }
      return n * (n + 1) / 2 - sum;
    }
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {3, 0, 1};
  cout << "Missing number: " << sol.missingNumber(nums) << endl;
}