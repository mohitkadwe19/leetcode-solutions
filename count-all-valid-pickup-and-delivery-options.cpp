#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countOrders(int n)
  {
    int count = 1;
    int prev_num = 2;
    int mod = 1e9 + 7;
    for (int i = 2; i <= n; i++)
    {
      count = (count * (((1ll * prev_num * (prev_num + 1)) / 2) + (prev_num + 1)) % mod) % mod;
      prev_num += 2;
    }
    return count;
  }
};

int main()
{
  int n = 1;
  Solution s;
  cout << s.countOrders(n) << endl;
  return 0;
}