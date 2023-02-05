#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long pickGifts(vector<int> &gifts, int k)
  {
    long long n = gifts.size();
    priority_queue<long long> pq;
    for (auto it : gifts)
    {
      pq.push(it);
    }
    long long sum = 0;
    while (k--)
    {
      pq.push(sqrt(pq.top()));
      pq.pop();
    }
    while (!pq.empty())
    {
      sum += pq.top();
      pq.pop();
    }
    return sum;
  }
};

int main()
{
  int k = 4;
  vector<int> gifts = {25, 64, 9, 4, 100};
  Solution ob;
  cout << ob.pickGifts(gifts, k) << endl;
  return 0;
}