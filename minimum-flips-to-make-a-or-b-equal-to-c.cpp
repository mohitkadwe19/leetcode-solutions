#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minFlips(int a, int b, int c)
  {
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
      int x = (a >> i) & 1;
      int y = (b >> i) & 1;
      int z = (c >> i) & 1;
      if (z == 0)
      {
        if (x == 1)
          ans++;
        if (y == 1)
          ans++;
      }
      else
      {
        if (x == 0 && y == 0)
          ans++;
      }
    }
    return ans;
  }
};

int main()
{
  int a = 2, b = 6, c = 5;
  Solution sol;
  cout << sol.minFlips(a, b, c) << endl;
  return 0;
}