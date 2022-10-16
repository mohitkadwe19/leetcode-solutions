#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int sumSquareDigit(int n)
  {
    int sum = 0;
    while (n)
    {
      int digit = n % 10;
      sum += (digit * digit);
      n = n / 10;
    }
    return sum;
  }
  bool isHappy(int n)
  {
    int slow = n, fast = n;
    do
    {
      slow = sumSquareDigit(slow);
      fast = sumSquareDigit(sumSquareDigit(fast));
    } while (slow != fast);
    if (slow == 1)
      return 1;
    return 0;
  }
};

int main()
{
  Solution s;
  int n = 19;
  cout << s.isHappy(n) << endl;
  return 0;
}