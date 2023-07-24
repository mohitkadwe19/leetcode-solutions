#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double myPow(double x, int n)
  {
    double ans = pow(x, n);
    return ans;
  }
};

int main()
{
  Solution s;
  cout << s.myPow(2.00000, 10) << endl;
  return 0;
}