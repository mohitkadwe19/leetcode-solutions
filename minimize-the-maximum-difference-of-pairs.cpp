#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int check(int mid, vector<int> &nums, int p, int n)
  {

    int in = 0;
    int cnt = 0;

    for (int i = 1; i < n; i++)
    {

      if (in)
      {
        in = 0;
        continue;
      }

      if (nums[i] - nums[i - 1] <= mid)
      {

        in = 1;
        cnt++;
      }
    }
    return cnt >= p;
  }

  int minimizeMax(vector<int> &nums, int p)
  {

    int n = nums.size();
    sort(begin(nums), end(nums));

    int low = 0, high = nums[n - 1] - nums[0];
    int ans = INT_MAX;

    while (low <= high)
    {

      int mid = low + (high - low) / 2;

      if (check(mid, nums, p, n))
      {

        ans = mid;
        high = mid - 1;
      }
      else
        low = mid + 1;
    }

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {3, 5, 9, 11};
  cout << s.minimizeMax(nums, 2);
  return 0;
}