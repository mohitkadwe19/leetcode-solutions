#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minSpeedOnTime(vector<int> &dist, double hour)
  {
    if (hour <= dist.size() - 1)
    {
      return -1;
    }
    int s = 1;
    int e = 1e7;
    while (s < e)
    {
      int mid = s + (e - s) / 2;
      double time = 0;
      for (int i = 0; i < dist.size() - 1; i++)
      {
        time += ceil((double)dist[i] / mid);
      }
      time += (double)dist[dist.size() - 1] / mid;
      if (time <= hour)
      {
        e = mid;
      }
      else
      {
        s = mid + 1;
      }
    }
    return s;
  }
};

int main()
{
  Solution s;
  vector<int> dist = {1, 3, 2};
  double hour = 6;
  cout << s.minSpeedOnTime(dist, hour);
  return 0;
}