#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int subarrayGCD(vector<int> &nums, int k)
  {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int gcd = nums[i];
      for (int j = i; j < n; j++)
      {
        gcd = __gcd(gcd, nums[j]);
        if (gcd == k)
        {
          ans++;
        }
      }
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {9, 3, 1, 2, 6, 3};
  int k = 3;
  cout << sol.subarrayGCD(nums, k) << endl;
  return 0;
}