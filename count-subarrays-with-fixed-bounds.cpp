#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long countSubarrays(vector<int> &nums, int minK, int maxK)
  {
    long long n = nums.size(), mni = -1, mxi = -1, li = -1, ans = 0;
    for (int i = 0; i < n; ++i)
    {
      if (nums[i] < minK || nums[i] > maxK)
      {
        li = i, mni = -1, mxi = -1;
      }
      else
      {
        if (nums[i] == minK)
        {
          mni = i;
        }
        if (nums[i] == maxK)
        {
          mxi = i;
        }
        if (mni != -1 && mxi != -1)
        {
          ans += min(mni, mxi) - li;
        }
      }
    }
    return ans;
  }
};

int main()
{
  int n, minK, maxK;
  cin >> n >> minK >> maxK;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  Solution obj;
  cout << obj.countSubarrays(nums, minK, maxK) << endl;
  return 0;
}