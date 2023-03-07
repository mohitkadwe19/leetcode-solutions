#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long minimumTime(vector<int> &time, int totalTrips)
  {
    long long maxtime = *max_element(time.begin(), time.end());
    long long l = 1, r = totalTrips * maxtime;
    while (l < r)
    {
      long long mid = (l + r) / 2, actualTrips = 0;
      for (int i = 0; i < time.size(); i++)
      {
        actualTrips += mid / time[i];
      }
      if (actualTrips < totalTrips)
      {
        l = mid + 1;
      }
      else
      {
        r = mid;
      }
    }
    return l;
  }
};

int main()
{

  vector<int> time = {1, 2, 3};
  int totalTrips = 5;
  Solution ob;
  cout << ob.minimumTime(time, totalTrips) << endl;
  return 0;
}