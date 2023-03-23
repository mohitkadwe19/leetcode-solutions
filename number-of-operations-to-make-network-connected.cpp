#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int makeConnected(int n, vector<vector<int>> &connections)
  {
    if (connections.size() < n - 1)
      return -1;
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);
    function<int(int)> find = [&](int x)
    {
      return parent[x] == x ? x : parent[x] = find(parent[x]);
    };
    for (auto &c : connections)
    {
      int x = find(c[0]), y = find(c[1]);
      if (x != y)
        parent[x] = y;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (parent[i] == i)
        ans++;
    return ans - 1;
  }
};

int main()
{
  Solution s;
  int n = 4;
  vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
  cout << s.makeConnected(n, connections) << endl;
  return 0;
}