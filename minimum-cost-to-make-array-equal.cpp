#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long solve(vector<int> &nums, vector<int> &cost, int mid)
  {
    long long sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      long long val = cost[i];
      val *= abs(nums[i] - mid);
      sum += val;
    }
    return sum;
  }
  long long minCost(vector<int> &nums, vector<int> &cost)
  {

    int s = *min_element(nums.begin(), nums.end());
    int e = *max_element(nums.begin(), nums.end());

    long long minCost = 1e18;
    while (s <= e)
    {
      int mid = (s + e) / 2;

      long long cos = solve(nums, cost, mid);
      long long a = solve(nums, cost, mid - 1);
      long long b = solve(nums, cost, mid + 1);

      if (minCost > cos)
      {
        minCost = cos;
      }
      if (a < cos)
      {
        e = mid - 1;
      }
      if (b < cos)
      {
        s = mid + 1;
      }
      else
      {
        e = mid - 1;
      }
    }
    return minCost;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {735103, 366367, 132236, 133334, 808160, 113001, 49051, 735598, 686615, 665317, 999793, 426087, 587000, 649989, 509946, 743518};
  vector<int> cost = {724182, 447415, 723725, 902336, 600863, 287644, 13836, 665183, 448859, 917248, 397790, 898215, 790754, 320604, 468575, 825614};
  cout << sol.minCost(nums, cost) << endl;
  return 0;
}