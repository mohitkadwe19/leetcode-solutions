#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
  {
    vector<int> ans;
    vector<int> in(n, 0);
    for (auto x : edges)
      in[x[1]]++;
    for (int i = 0; i < n; i++)
      if (in[i] == 0)
        ans.push_back(i);
    return ans;
  }
};

int main()
{
  Solution s;
  int n = 6;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
  vector<int> ans = s.findSmallestSetOfVertices(n, edges);
  for (auto x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}