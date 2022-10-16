#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    unordered_map<int, int> m;
    int n = nums.size();
    // insert all elements in the map
    for (int i = 0; i < n; i++)
    {
      m[nums[i]]++;
    }

    // find the element with max frequency
    int max = 0;
    int ans = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
      if (it->second > max)
      {
        max = it->second;
        ans = it->first;
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> arr = {3, 5, 3};
  cout << s.majorityElement(arr) << endl;
  return 0;
}