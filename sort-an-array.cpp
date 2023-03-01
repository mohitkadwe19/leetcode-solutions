#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> sortArray(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    return nums;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {5, 2, 3, 1};
  vector<int> ans = s.sortArray(nums);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}