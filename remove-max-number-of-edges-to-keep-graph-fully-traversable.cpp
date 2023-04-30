#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int find(vector<int> &parent, int x)
  {
    if (parent[x] != x)
      parent[x] = find(parent, parent[x]);
    return parent[x];
  }
  int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
  {
    int ans = 0;
    vector<int> parentA(n + 1), parentB(n + 1);
    for (int i = 1; i <= n; i++)
    {
      parentA[i] = i;
      parentB[i] = i;
    }
    for (auto &edge : edges)
    {
      if (edge[0] == 3)
      {
        int a = find(parentA, edge[1]);
        int b = find(parentA, edge[2]);
        if (a == b)
          ans++;
        else
          parentA[a] = b;
        parentB[a] = b;
      }
    }
    for (auto &edge : edges)
    {
      if (edge[0] == 1)
      {
        int a = find(parentA, edge[1]);
        int b = find(parentA, edge[2]);
        if (a == b)
          ans++;
        else
          parentA[a] = b;
      }
      else if (edge[0] == 2)
      {
        int a = find(parentB, edge[1]);
        int b = find(parentB, edge[2]);
        if (a == b)
          ans++;
        else
          parentB[a] = b;
      }
    }
    for (int i = 2; i <= n; i++)
    {
      if (find(parentA, i) != find(parentA, i - 1))
        return -1;
      if (find(parentB, i) != find(parentB, i - 1))
        return -1;
    }
    return ans;
  }
};

int main()
{
  int n = 4;
  vector<vector<int>> edges = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
  Solution sol;
  cout << sol.maxNumEdgesToRemove(n, edges) << endl;
  return 0;
}