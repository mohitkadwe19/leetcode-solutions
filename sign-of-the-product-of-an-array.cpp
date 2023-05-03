#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int arraySign(vector<int> &nums)
  {
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 0)
        return 0;
      if (nums[i] < 0)
        count++;
    }
    if (count % 2 == 0)
      return 1;
    return -1;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {-1, -2, -3, -4, 3, 2, 1};
  cout << sol.arraySign(nums) << endl;
  return 0;
}