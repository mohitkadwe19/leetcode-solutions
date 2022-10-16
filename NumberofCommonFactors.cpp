#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int commonFactors(int a, int b)
  {
    int count = 0;
    for (int i = 1; i <= min(a, b); i++)
    {
      if (a % i == 0 && b % i == 0)
      {
        count++;
      }
    }
    return count;
  }
};
int main()
{
  Solution s;
  int a = 12, b = 6;
  cout << s.commonFactors(a, b) << endl;
  return 0;
}