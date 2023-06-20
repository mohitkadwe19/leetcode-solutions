#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> getAverages(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<long long> prefixSum(n);
    vector<int> result(n, -1);
    if (n < 2 * k + 1)
    {
      return result;
    }
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
      prefixSum[i] = nums[i] + prefixSum[i - 1];
    }
    for (int i = k; i < n - k; i++)
    {
      long long sum;
      if (i - k == 0)
      {
        sum = prefixSum[i + k];
      }
      else
      {
        sum = prefixSum[i + k] - prefixSum[i - k - 1];
      }
      result[i] = sum / (2 * k + 1);
    }
    return result;
  }
};

int main()
{
  vector<int> nums = {7, 4, 3, 9, 1, 8, 5, 2, 6};
  int k = 3;
  Solution sol;
  vector<int> ans = sol.getAverages(nums, k);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}