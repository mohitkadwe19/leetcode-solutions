#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maxKelements(vector<int> &nums, int k)
  {

    priority_queue<int> pq;

    for (auto it : nums)
    {
      pq.push(it);
    }
    long long ans = 0;

    for (int i = 0; i < k; i++)
    {
      int topElement = pq.top();
      pq.pop();
      ans += topElement;
      int newElement = ceil((topElement * 1.0) / 3);
      pq.push(newElement);
    }

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 10, 3, 3, 3};
  int k = 3;
  cout << s.maxKelements(nums, k) << endl;
  return 0;
}