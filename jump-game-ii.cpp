#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int jump(vector<int> &nums)
  {
    int n = nums.size();
    int ans = 0;
    int cur = 0;
    int next = 0;
    for (int i = 0; i < n; i++)
    {
      if (i > cur)
      {
        cur = next;
        ans++;
      }
      next = max(next, i + nums[i]);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {2, 3, 1, 1, 4};
  cout << s.jump(nums) << endl;
  return 0;
}