#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int largestAltitude(vector<int> &gain)
  {
    int max = 0, sum = 0;
    for (int i = 0; i < gain.size(); i++)
    {
      sum += gain[i];
      if (sum > max)
        max = sum;
    }
    return max;
  }
};

int main()
{
  Solution s;
  vector<int> gain = {-5, 1, 5, 0, -7};
  cout << s.largestAltitude(gain) << endl;
  return 0;
}