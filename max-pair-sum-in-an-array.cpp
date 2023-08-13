#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getMaximumDigit(int num)
  {
    int maxDigit = 0;
    while (num > 0)
    {
      maxDigit = max(maxDigit, num % 10);
      num /= 10;
    }
    return maxDigit;
  }

  int maxSum(vector<int> &nums)
  {
    unordered_map<int, int> maxDigitToMaxSum;
    int maxSum = -1;

    for (int num : nums)
    {
      int maxDigit = getMaximumDigit(num);
      if (maxDigitToMaxSum.count(maxDigit))
      {
        maxSum = max(maxSum, maxDigitToMaxSum[maxDigit] + num);
        maxDigitToMaxSum[maxDigit] = max(maxDigitToMaxSum[maxDigit], num);
      }
      else
      {
        maxDigitToMaxSum[maxDigit] = num;
      }
    }

    return maxSum;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {3, 5, 2, 4, 1};
  cout << sol.maxSum(nums) << endl;
  return 0;
}