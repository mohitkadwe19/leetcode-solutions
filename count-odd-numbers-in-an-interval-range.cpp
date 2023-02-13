#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countOdds(int low, int high)
  {
    return ((high + 1) / 2) - (low / 2);
  }
};

int main()
{
  Solution s;
  int low = 800445804, high = 979430543;
  cout << s.countOdds(low, high) << endl;
  return 0;
}