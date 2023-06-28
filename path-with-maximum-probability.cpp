#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
  {

    vector<vector<pair<int, double>>> graph(n);
    for (int i = 0; i < edges.size(); i++)
    {
      graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
      graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }

    vector<double> prob(n, 0);
    prob[start] = 1;
    priority_queue<pair<double, int>> pq;
    pq.push({1, start});

    while (!pq.empty())
    {
      auto curr = pq.top();
      pq.pop();
      int node = curr.second;
      double currProb = curr.first;

      for (auto child : graph[node])
      {
        int childNode = child.first;
        double childProb = child.second;

        if (currProb * childProb > prob[childNode])
        {
          prob[childNode] = currProb * childProb;
          pq.push({prob[childNode], childNode});
        }
      }
    }

    return prob[end];
  }
};

int main()
{
  Solution s;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
  vector<double> succProb = {0.5, 0.5, 0.2};
  cout << s.maxProbability(3, edges, succProb, 0, 2) << endl;
  return 0;
}