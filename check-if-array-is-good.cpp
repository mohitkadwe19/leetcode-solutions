#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isGood(vector<int> &nums)
  {
    int n = *max_element(nums.begin(), nums.end());
    if (nums.size() != n + 1)
    {
      return false;
    }

    unordered_map<int, int> frequency;
    for (int num : nums)
    {
      frequency[num]++;
    }

    for (int i = 1; i < n; i++)
    {
      if (frequency[i] != 1)
      {
        return false;
      }
    }

    if (frequency[n] != 2)
    {
      return false;
    }

    return true;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {2, 1, 3};
  cout << s.isGood(nums);
  return 0;
}