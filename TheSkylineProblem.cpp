#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
  {
    vector<vector<int>> res;
    vector<pair<int, int>> height;
    multiset<int> m;
    int pre = 0, cur = 0;
    for (auto a : buildings)
    {
      height.push_back({a[0], -a[2]});
      height.push_back({a[1], a[2]});
    }
    sort(height.begin(), height.end());
    m.insert(0);
    for (auto h : height)
    {
      if (h.second < 0)
        m.insert(-h.second);
      else
        m.erase(m.find(h.second));
      cur = *m.rbegin();
      if (cur != pre)
      {
        res.push_back({h.first, cur});
        pre = cur;
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
  vector<vector<int>> ans = s.getSkyline(buildings);
  for (auto v : ans)
  {
    for (auto i : v)
    {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}