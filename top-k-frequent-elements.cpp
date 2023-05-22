#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    unordered_map<int, int> freq;
    for (auto i : nums)
    {
      freq[i]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto i : freq)
    {
      pq.push({i.second, i.first});
    }
    vector<int> ans;
    while (k--)
    {
      ans.push_back(pq.top().second);
      pq.pop();
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;
  vector<int> ans = s.topKFrequent(nums, k);
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}