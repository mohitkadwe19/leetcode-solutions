#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canEatAllBananas(vector<int> &piles, int h, int k)
  {
    int time = 0;
    for (int pile : piles)
      time += (pile + k - 1) / k;
    return time <= h;
  }
  int minEatingSpeed(vector<int> &piles, int h)
  {
    int l = 1, r = 1e9;
    while (l < r)
    {
      int mid = l + (r - l) / 2;
      if (canEatAllBananas(piles, h, mid))
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }
};

int main()
{
  Solution s;
  vector<int> piles = {3, 6, 7, 11};
  int h = 8;
  cout << s.minEatingSpeed(piles, h) << endl;
  return 0;
}