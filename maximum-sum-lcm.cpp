#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long int maxSumLCM(int n)
  {
    long long sum = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
      if (n % i == 0)
      {
        sum += n / i;
        if (n / i != i)
        {
          sum += i;
        }
      }
    }

    return sum;
  }
};

int main()
{
  Solution sol;
  int n = 2;
  cout << sol.maxSumLCM(n) << endl;
  return 0;
}