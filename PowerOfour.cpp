#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPowerOfFour(int n)
  {
    if (n <= 0)
    {
      return false;
    }
    else
    {
      while (n > 1)
      {
        if (n % 4 != 0)
          return false;
        else
          n = n / 4;
      }
      return true;
    }
  }
};

int main()
{
  Solution s;
  int t;
  cin >> t;
  cout << s.isPowerOfFour(t) << endl;
}