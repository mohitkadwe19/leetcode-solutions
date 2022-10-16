#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumCost(vector<int> &cost)
  {
    // sort the cost array in ascending order
    sort(cost.begin(), cost.end());
    int n = cost.size();
    int sum = 0;

    if (n == 1)
    {
      return cost[0];
    }
    if (n == 2)
    {
      return cost[0] + cost[1];
    }
    if (n == 3)
    {
      return cost[1] + cost[2];
    }

    int count = 2;
    for (int i = n - 1; i >= 0; i--)
    {
      sum = sum + cost[i];
      count--;
      if (count == 0)
      {
        count = 2;
        i--;
      }
    }
    return sum;
  }
};

int main()
{
  Solution s;
  vector<int> cost = {6, 5, 7, 9, 2, 2};
  cout << s.minimumCost(cost) << endl;
  return 0;
}