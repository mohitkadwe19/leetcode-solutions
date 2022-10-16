#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int concatenatedBinary(int n)
  {
    long long sum = 0;
    long long MOD = 1e9 + 7;
    for (int i = 1; i <= n; i++)
    {
      int x = i;
      int len = 0;
      while (x)
      {
        x >>= 1;
        len++;
      }
      sum = ((sum << len) % MOD + i) % MOD;
    }
    return sum;
  }
};

int main()
{
  Solution s;
  int n = 3;
  cout << s.concatenatedBinary(n) << endl;
  return 0;
}