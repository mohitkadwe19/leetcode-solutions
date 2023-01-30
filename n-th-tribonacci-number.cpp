#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int tribonacci(int n)
  {
    int t1 = 1, t2 = 1;
    if (n == 0)
    {
      return 0;
    }
    else if (n == 1 || n == 2)
    {
      return 1;
    }
    else if (n == 3)
    {
      return 2;
    }
    else
    {
      int t3 = 2;
      for (int i = 4; i <= n; i++)
      {
        int t4 = t1 + t2 + t3;
        t1 = t2;
        t2 = t3;
        t3 = t4;
      }
      return t3;
    }
  }
};

int main()
{
  int n = 4;
  Solution s;
  cout << s.tribonacci(n) << endl;
  return 0;
}