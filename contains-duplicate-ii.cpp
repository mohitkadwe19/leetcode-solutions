#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
      if (m.find(nums[i]) != m.end() and abs(m[nums[i]] - i) <= k)
      {
        return true;
      }
      m[nums[i]] = i;
    }
    return false;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3, 1};
  int k = 3;
  cout << sol.containsNearbyDuplicate(nums, k) << endl;
  return 0;
}