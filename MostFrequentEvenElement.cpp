#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int mostFrequentEven(vector<int> &nums)
  {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] % 2 == 0)
      {
        m[nums[i]]++;
      }
    }

    int max = 0;
    int ans = -1;
    // check if there is a tie between two elements with same frequency and return the smaller one
    for (auto it = m.begin(); it != m.end(); it++)
    {
      if (it->second > max)
      {
        max = it->second;
        ans = it->first;
      }
      else if (it->second == max)
      {
        ans = min(ans, it->first);
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {4, 4, 4, 9, 2, 4};
  cout << s.mostFrequentEven(nums) << endl;
  return 0;
}