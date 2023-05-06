#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numSubseq(vector<int> &nums, int target)
  {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int l = 0, r = n - 1;
    int ans = 0;
    int mod = 1e9 + 7;
    vector<int> pows(n);
    pows[0] = 1;
    for (int i = 1; i < n; i++)
      pows[i] = (pows[i - 1] * 2) % mod;
    while (l <= r)
    {
      if (nums[l] + nums[r] > target)
        r--;
      else
      {
        ans = (ans + pows[r - l]) % mod;
        l++;
      }
    }
    return ans;
  }
};

int main()
{
  vector<int> nums{3, 5, 6, 7};
  int target = 9;
  Solution sol;
  cout << sol.numSubseq(nums, target) << endl;
  return 0;
}