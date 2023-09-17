#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countSetBits(int num)
  {
    int count = 0;
    while (num)
    {
      count += num & 1;
      num >>= 1;
    }
    return count;
  }

  int sumIndicesWithKSetBits(vector<int> &nums, int k)
  {
    int totalSum = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
      int setBitsCount = countSetBits(i);
      if (setBitsCount == k)
      {
        totalSum += nums[i];
      }
    }

    return totalSum;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3, 4};
  int k = 5;
  cout << sol.sumIndicesWithKSetBits(nums, k);
  return 0;
}