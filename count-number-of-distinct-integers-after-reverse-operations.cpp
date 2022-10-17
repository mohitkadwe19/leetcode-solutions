#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countDistinctIntegers(vector<int> &nums)
  {
    int n = nums.size();
    set<int> s;
    for (int i = 0; i < n; i++)
    {
      s.insert(nums[i]);
      int num = nums[i];
      int rev = 0;
      while (num)
      {
        rev = rev * 10 + num % 10;
        num /= 10;
      }
      s.insert(rev);
    }
    return s.size();
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 13, 10, 12, 31};
  cout << sol.countDistinctIntegers(nums) << endl;
  return 0;
}