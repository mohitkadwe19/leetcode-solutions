#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumRightShifts(vector<int> &nums)
  {
    int n = nums.size();

    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());

    for (int i = 0; i < n; ++i)
    {
      if (nums == sorted_nums)
      {
        return i;
      }

      vector<int> temp(n);
      for (int j = 0; j < n; ++j)
      {
        temp[(j + 1) % n] = nums[j];
      }
      nums = temp;
    }

    return -1;
  }
};

int main()
{
  vector<int> nums = {3, 4, 5, 1, 2};
  Solution s;
  cout << s.minimumRightShifts(nums) << endl;
  return 0;
}