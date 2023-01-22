#include <bits/stdc++.h>
using namespace std;

int alternateDigitSum(int n)
{
  vector<int> digits = {0};
  bool flag = 1;
  int sum = 0;

  while (n != 0)
  {
    int rem = n % 10;
    digits.push_back(rem);
    n = n / 10;
  }
  reverse(digits.begin(), digits.end());

  for (int val : digits)
  {
    if (flag)
    {
      sum += val;
    }
    else
    {
      sum -= val;
    }
    flag = !flag;
  }

  return sum;
}

int main()
{
  int n;
  cin >> n;
  cout << alternateDigitSum(n);
  return 0;
}