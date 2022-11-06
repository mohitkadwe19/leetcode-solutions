#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
  long long maximumSubarraySum(vector<int> &nums, int k)
  {
    unordered_map<ll, ll> mp;
    ll i = 0, sum = 0, j = 0, res = INT_MIN;

    while (i < k - 1)
    {
      mp[nums[i]]++;
      sum += nums[i];
      i++;
    }

    while (i < nums.size())
    {
      mp[nums[i]]++;

      sum += nums[i];

      if (mp.size() == k)
      {
        res = max(res, sum);
      }

      sum -= nums[j];

      if (mp[nums[j]] == 1)
      {
        mp.erase(nums[j]);
      }
      else
      {
        mp[nums[j]]--;
      }

      j++;

      i++;
    }

    if (res == INT_MIN)
    {
      return 0;
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
  int k = 3;
  cout << s.maximumSubarraySum(nums, k) << endl;
  return 0;
}