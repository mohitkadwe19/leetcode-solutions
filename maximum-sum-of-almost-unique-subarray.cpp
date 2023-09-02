#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maxSum(vector<int> &nums, int m, int k)
  {
    unordered_map<int, int> countMap;
    int distinct = 0;
    long sum = 0, maxSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      int num = nums[i];

      countMap[num] = countMap.find(num) != countMap.end() ? countMap[num] + 1 : 1;
      if (countMap[num] == 1)
      {
        distinct++;
      }

      sum += num;

      if (i >= k)
      {
        int prev = nums[i - k];
        countMap[prev]--;
        if (countMap[prev] == 0)
        {
          distinct--;
        }
        sum -= prev;
      }

      if (i >= k - 1 && distinct >= m)
      {
        maxSum = std::max(maxSum, sum);
      }
    }

    return maxSum;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {4, 4, 4, 9, 2, 4};
  cout << sol.maxSum(nums, 2, 2) << endl;
  return 0;
}