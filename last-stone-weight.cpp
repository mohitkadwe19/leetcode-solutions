#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int lastStoneWeight(vector<int> &stones)
  {
    priority_queue<int> pq;
    for (int i = 0; i < stones.size(); i++)
      pq.push(stones[i]);
    while (pq.size() > 1)
    {
      int x = pq.top();
      pq.pop();
      int y = pq.top();
      pq.pop();
      if (x != y)
        pq.push(x - y);
    }
    return pq.empty() ? 0 : pq.top();
  }
};

int main()
{
  Solution solution;
  vector<int> stones = {2, 7, 4, 1, 8, 1};
  cout << solution.lastStoneWeight(stones) << endl;
  return 0;
}