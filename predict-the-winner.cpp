#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int find(vector<int> &nums, int s, int e, bool sec)
  {
    if (s >= e)
    {
      if (sec)
        return -nums[s];
      else
        return nums[s];
    }
    if (sec)
    {
      return min(-nums[s] + find(nums, s + 1, e, !sec), -nums[e] + find(nums, s, e - 1, !sec));
    }
    else
    {
      return max(nums[s] + find(nums, s + 1, e, !sec), nums[e] + find(nums, s, e - 1, !sec));
    }
  }
  bool PredictTheWinner(vector<int> &nums)
  {
    int sum = 0;
    int a = find(nums, 0, nums.size() - 1, false);
    return (a >= 0);
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 5, 2};
  cout << s.PredictTheWinner(nums) << endl;
  return 0;
}