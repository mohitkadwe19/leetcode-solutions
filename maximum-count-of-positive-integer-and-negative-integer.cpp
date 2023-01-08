#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximumCount(vector<int> &nums)
  {
    int negative = 0, positive = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] > 0)
      {
        positive++;
      }
      else if (nums[i] < 0)
      {
        negative++;
      }
    }

    int ans = max(negative, positive);

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {-3, -2, -1, 0, 0, 1, 2};
  cout << s.maximumCount(nums) << endl;
  return 0;
}
