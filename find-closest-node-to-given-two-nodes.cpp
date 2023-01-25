#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int closestMeetingNode(vector<int> &edges, int node1, int node2)
  {
    pair<int, int> ans = {1e9, -1};
    map<int, int> adist, bdist;
    while (node1 != -1 and adist.count(node1) == 0)
    {
      adist[node1] = adist.size();
      node1 = edges[node1];
    }
    while (node2 != -1 and bdist.count(node2) == 0)
    {
      bdist[node2] = bdist.size();
      node2 = edges[node2];
    }
    for (auto u : adist)
    {
      if (bdist.count(u.first) > 0)
        ans = min(make_pair(max(u.second, bdist[u.first]), u.first), ans);
    }
    return ans.second;
  }
};

int main()
{
  Solution s;
  vector<int> edges = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  cout << s.closestMeetingNode(edges, 1, 12) << endl;
  return 0;
}