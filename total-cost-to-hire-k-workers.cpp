#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
  long long totalCost(vector<int> &costs, int k, int candidates)
  {
    ll res = 0;
    int i = 0, count = 0, j = costs.size() - 1;

    priority_queue<int, vector<int>, greater<int>> pq_1;
    priority_queue<int, vector<int>, greater<int>> pq_2;

    while (i < candidates)
    {
      pq_1.push(costs[i]);
      i++;
    }

    if (candidates > costs.size() - candidates)
    {

      candidates = costs.size() - candidates;
    }

    while (count < candidates)
    {
      pq_2.push(costs[j]);
      count++;
      j--;
    }

    while (k--)
    {
      if (pq_1.size() == 0)
      {
        res += pq_2.top();

        pq_2.pop();

        if (i <= j)
        {
          pq_2.push(costs[j]);
          j--;
        }
      }
      else if (pq_2.size() == 0)
      {

        res += pq_1.top();

        pq_1.pop();

        if (i <= j)
        {
          pq_1.push(costs[i]);
          i++;
        }
      }
      else if (pq_1.top() <= pq_2.top())
      {
        res += pq_1.top();

        pq_1.pop();

        if (i <= j)
        {
          pq_1.push(costs[i]);
          i++;
        }
      }
      else
      {
        res += pq_2.top();

        pq_2.pop();

        if (i <= j)
        {
          pq_2.push(costs[j]);
          j--;
        }
      }
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> costs = {17, 12, 10, 2, 7, 2, 11, 20, 8};
  int k = 3;
  int candidates = 4;
  cout << s.totalCost(costs, k, candidates) << endl;
  return 0;
}
