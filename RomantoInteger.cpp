#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int romanToInt(string s)
  {
    long long sum = 0;

    int I = 1;
    int V = 5;
    int X = 10;
    int L = 50;
    int C = 100;
    int D = 500;
    int M = 1000;

    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == 'I')
      {
        if (s[i + 1] == 'V' or s[i + 1] == 'X')
        {
          sum = sum - I;
        }
        else
        {
          sum = sum + I;
        }
      }
      if (s[i] == 'V')
      {
        sum = sum + V;
      }
      if (s[i] == 'X')
      {
        if (s[i + 1] == 'L' or s[i + 1] == 'C')
        {
          sum = sum - X;
        }
        else
        {
          sum = sum + X;
        }
      }
      if (s[i] == 'L')
      {
        sum = sum + L;
      }
      if (s[i] == 'C')
      {
        if (s[i + 1] == 'D' or s[i + 1] == 'M')
        {
          sum = sum - C;
        }
        else
        {
          sum = sum + C;
        }
      }
      if (s[i] == 'D')
      {
        sum = sum + D;
      }
      if (s[i] == 'M')
      {
        sum = sum + M;
      }
    }

    return sum;
  }
};

int main()
{
  Solution sol;
  string s = "MCMXCIV";
  cout << sol.romanToInt(s) << endl;
  return 0;
}