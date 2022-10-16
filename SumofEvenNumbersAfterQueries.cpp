#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
  {
    int n = nums.size();
    int m = queries.size();
    vector<int> ans(m, 0);
    int sum = 0;

    for (auto num : nums)
    {
      if (num % 2 == 0)
      {
        sum += num;
      }
    }

    for (int i = 0; i < m; ++i)
    {
      int index = queries[i][1];
      int val = queries[i][0];
      if (nums[index] % 2 == 0)
        sum -= nums[index];
      nums[index] += val;
      if (nums[index] % 2 == 0)
        sum += nums[index];
      ans[i] = sum;
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3, 4};
  vector<vector<int>> queries = {{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};
  vector<int> res = sol.sumEvenAfterQueries(nums, queries);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}