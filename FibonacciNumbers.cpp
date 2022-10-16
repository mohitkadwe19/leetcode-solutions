#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int fib(int n)
  {
    int f0 = 0, f1 = 1, f = 0;
    if (n == 0)
    {
      return 0;
    }
    else if (n == 1)
    {
      return 1;
    }
    else
    {
      for (int i = 2; i <= n; ++i)
      {
        f = f1 + f0;
        f0 = f1;
        f1 = f;
      }
      return f1;
    }
  }
};

int main()
{
  Solution s;
  int t;
  cin >> t;
  cout << s.fib(t);
  return 0;
}