#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countPairs(vector<int> &nums, int target)
  {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
      for (int j = i + 1; j < n; ++j)
      {
        if (nums[i] + nums[j] < target)
        {
          count++;
        }
      }
    }

    return count;
  }
};

int main()
{
  vector<int> ans = {-1, 1, 2, 3, 1};
  int target = 5;
  Solution s;
  cout << s.countPairs(ans, target) << endl;
  return 0;
}