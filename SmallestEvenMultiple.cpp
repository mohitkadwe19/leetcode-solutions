#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int smallestEvenMultiple(int n)
  {

    if (n % 2 == 0)
    {
      return n;
    }
    else
    {
      return n * 2;
    }
  }
};

int main()
{
  Solution sol;
  int n = 5;
  cout << sol.smallestEvenMultiple(n) << endl;
}