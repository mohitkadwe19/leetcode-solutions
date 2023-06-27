#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  typedef pair<int, pair<int, int>> pp;
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
  {
    priority_queue<pp> que;
    for (int n : nums1)
    {
      for (int m : nums2)
      {
        if (que.size() < k)
          que.push({n + m, {n, m}});
        else if (n + m < que.top().first)
        {
          que.pop();
          que.push({n + m, {n, m}});
        }
        else
          break;
      }
    }

    int size = que.size();
    vector<vector<int>> ans(size);
    int index = size - 1;
    while (!que.empty())
    {
      ans[index] = {que.top().second.first, que.top().second.second};
      que.pop();
      index--;
    }

    return ans;
  }
};

int main()
{
  vector<int> v1 = {1, 7, 11};
  vector<int> v2 = {2, 4, 6};
  int k = 3;
  Solution sol;
  vector<vector<int>> ans = sol.kSmallestPairs(v1, v2, k);
  for (auto i : ans)
  {
    for (auto j : i)
      cout << j << " ";
    cout << endl;
  }
  return 0;
}