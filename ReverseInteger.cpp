#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{

  if (x > INT32_MAX || x <= INT32_MIN)
  {
    return 0;
  }
  int p = 1;
  if (x < 0)
  {
    p = -1;
    x = x * (-1);
  }

  long rev = 0;
  while (x > 0)
  {
    try
    {
      rev = rev * 10 + x % 10;
    }
    catch (int)
    {
      return 0;
    }
    x = x / 10;
  }

  if (rev >= INT32_MAX || rev < INT32_MIN)
  {
    return 0;
  }

  return rev * p;
}

int main()
{
  long long n;
  cin >> n;
  cout << reverse(n);
}