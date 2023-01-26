#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
  {
    unordered_map<int, vector<pair<int, int>>> graph;
    for (auto e : flights)
      graph[e[0]].push_back({e[1], e[2]});
    vector<int> prices(n, -1);
    queue<pair<int, int>> q;
    q.push({src, 0});
    ++k;
    while (!q.empty())
    {
      if (!k)
      {
        break;
      }
      int len = q.size();
      for (int i = 0; i < len; i++)
      {
        auto cur = q.front();
        q.pop();
        for (auto e : graph[cur.first])
        {
          int price = cur.second + e.second;
          if (prices[e.first] == -1 || price < prices[e.first])
          {
            prices[e.first] = price;
            q.push({e.first, price});
          }
        }
      }
      k--;
    }
    return prices[dst];
  }
};

int main()
{
  Solution sol;
  int n = 3;
  vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  int src = 0, dst = 2, k = 1;
  cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl;
  return 0;
}