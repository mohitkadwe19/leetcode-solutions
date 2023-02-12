#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long findTheArrayConcVal(vector<int> &nums)
  {
    long long ans = 0, n = nums.size();
    while (n)
    {
      int first = nums[0], last = nums[n - 1];
      if (n == 1)
      {
        ans += first;
        n--;
        nums.erase(nums.begin());
      }
      else
      {
        long long x = pow(10, (int)log10(last) + 1);
        ans += x * first + last;
        n -= 2;
        nums.erase(nums.begin());
        nums.erase(nums.end() - 1);
      }
    }

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {7, 52, 2, 4};
  cout << s.findTheArrayConcVal(nums) << endl;
  return 0;
}