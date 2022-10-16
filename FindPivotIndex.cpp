#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int pivotIndex(vector<int> &nums)
  {
    int size = nums.size();
    int leftSum = 0;
    int rightSum = 0;
    for (int i = 0; i < size; i++)
    {
      leftSum = 0;
      for (int j = 0; j < i; j++)
      {
        leftSum += nums[j];
      }

      rightSum = 0;
      for (int j = i + 1; j < size; j++)
      {
        rightSum += nums[j];
      }

      if (leftSum == rightSum)
      {
        return i;
      }
    }
    return -1;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 7, 3, 6, 5, 6};
  cout << s.pivotIndex(nums);
  return 0;
}