#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long countBadPairs(vector<int> &nums)
  {
    long long ans = 0;
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
      ans += i - mp[nums[i] - i];
      mp[nums[i] - i]++;
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {4, 1, 3, 3};
  cout << "The number of bad pairs is " << sol.countBadPairs(nums) << endl;
}