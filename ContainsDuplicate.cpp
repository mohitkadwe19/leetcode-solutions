#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool containsDuplicate(vector<int> &nums)
  {

    // add all the elements to a unordered_map
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
      m[nums[i]]++;
    }
    // if any element is repeated more than once, return true
    for (auto it = m.begin(); it != m.end(); it++)
    {
      if (it->second > 1)
      {
        return true;
      }
    }
    return false;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 1};
  cout << s.containsDuplicate(nums) << endl;
  return 0;
}