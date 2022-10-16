#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
  // int result = 0;
  // for (int i = 0; i < nums.size(); i++)
  // {
  //   result ^= nums[i];
  // }
  // return result;

  unordered_map<int, int> hash;
  for (auto x : nums)
  {
    hash[x]++;
  }
  for (auto x : nums)
  {
    if (hash[x] == 1)
      return x;
  }
  return -1;
}

int main()
{
  vector<int> nums = {4, 1, 2, 1, 2};
  cout << singleNumber(nums) << endl;
}