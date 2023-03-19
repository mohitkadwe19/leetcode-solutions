#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> evenOddBit(int n)
  {
    vector<int> res(2, 0);
    int i = 0;
    while (n)
    {
      if (n & 1)
        res[i]++;
      n >>= 1;
      i = 1 - i;
    }
    return res;
  }
};

int main()
{
  int n = 17;
  Solution s;
  vector<int> res = s.evenOddBit(n);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}