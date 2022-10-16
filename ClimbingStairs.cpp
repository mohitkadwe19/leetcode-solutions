#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int climbStairs(int n)
  {
    int a = 1, b = 1;
    for (int i = 2; i <= n; i++)
    {
      int c = a + b;
      a = b;
      b = c;
    }
    return b;
  }
};

int main()
{
  Solution s;
  cout << s.climbStairs(3) << endl;
  return 0;
}