#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> summaryRanges(vector<int> &nums)
  {
    vector<string> ans;
    int n = nums.size();
    if (n == 0)
      return ans;
    int start = nums[0];
    int end = nums[0];
    for (int i = 1; i < n; i++)
    {
      if (nums[i] == end + 1)
      {
        end = nums[i];
      }
      else
      {
        if (start == end)
        {
          ans.push_back(to_string(start));
        }
        else
        {
          ans.push_back(to_string(start) + "->" + to_string(end));
        }
        start = nums[i];
        end = nums[i];
      }
    }
    if (start == end)
    {
      ans.push_back(to_string(start));
    }
    else
    {
      ans.push_back(to_string(start) + "->" + to_string(end));
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {0, 1, 2, 4, 5, 7};
  vector<string> ans = s.summaryRanges(nums);
  for (auto x : ans)
  {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}