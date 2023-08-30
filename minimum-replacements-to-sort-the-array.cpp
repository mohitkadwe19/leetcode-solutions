#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long minimumReplacement(vector<int> &nums)
  {
    int n = nums.size();
    long long operation = 0;

    for (int i = n - 2; i >= 0; i--)
    {

      // everything are fine then continue;
      if (nums[i] < nums[i + 1])
      {
        continue;
      }

      else
      { // nums[i] > nums[i+1]

        // fact 1:- find part
        int part = nums[i] / nums[i + 1];

        // fact2:- % != 0 then part++  =>  2;
        if (nums[i] % nums[i + 1] != 0)
        {
          part++;
        }
        // all operation = part - 1;
        operation += part - 1;

        /// fact3 :- who is part are choose
        nums[i] = nums[i] / part;
      }
    }

    return operation;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 3, 2, 2};
  cout << Solution().minimumReplacement(nums);
  return 0;
}
