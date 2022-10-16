#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumOperations(vector<int> &nums)
  {
    // sort the nums
    sort(nums.begin(), nums.end());

    int operations = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] > 0)
      {

        int tmp = nums[i];
        operations++;

        for (int j = i; j < nums.size(); j++)
        {
          nums[j] = nums[j] - tmp;
        }
      }
    }
    return operations;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 5, 0, 3, 5};
  cout << s.minimumOperations(nums) << endl;
  return 0;
}