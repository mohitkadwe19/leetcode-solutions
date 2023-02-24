#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumDeviation(vector<int> &nums)
  {
    int n = nums.size();
    priority_queue<int> pq;
    int minVal = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] % 2 == 1)
        nums[i] *= 2;
      pq.push(nums[i]);
      minVal = min(minVal, nums[i]);
    }
    int ans = INT_MAX;
    while (pq.top() % 2 == 0)
    {
      int top = pq.top();
      pq.pop();
      ans = min(ans, top - minVal);
      top /= 2;
      pq.push(top);
      minVal = min(minVal, top);
    }
    return min(ans, pq.top() - minVal);
  }
};

int main()
{
  vector<int> nums = nums = {1, 2, 3, 4};
  Solution obj;
  cout << obj.minimumDeviation(nums) << endl;
  return 0;
}