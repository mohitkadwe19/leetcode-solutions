#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
  if (nums.empty())
    return 0;
  int n = nums.size();
  int k = 0;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] != nums[k])
    {
      k++;
      nums[k] = nums[i];
    }
  }
  return k + 1;
}

int main()
{
  vector<int> nums = {1, 1, 2};
  cout << removeDuplicates(nums) << endl;
  return 0;
}