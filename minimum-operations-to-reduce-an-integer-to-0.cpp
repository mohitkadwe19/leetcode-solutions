#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minOperations(int n)
  {
    if (n == 0)
    {
      return 0;
    }
    int c = floor(1.0 * log(n) / log(2)), d = ceil(1.0 * log2(n));
    if (abs(pow(2, c) - n) > abs(pow(2, d) - n))
    {
      return (1 + minOperations((abs(pow(2, d) - n))));
    }
    else
    {
      return (1 + minOperations((abs(pow(2, c) - n))));
    }
  }
};

int main()
{
  int n = 39;
  cout << Solution().minOperations(n) << endl;
  return 0;
}