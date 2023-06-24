#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestString(int x, int y, int z)
  {
    int res = min(x, y);
    if (x == y)
    {
      return 2 * (z + 2 * res);
    }
    else
    {
      return 2 * (1 + z + 2 * res);
    }
  }
};

int main()
{
  Solution s;
  int x = 2, y = 5, z = 1;
  int ans = s.longestString(x, y, z);
  cout << ans << endl;
  return 0;
}