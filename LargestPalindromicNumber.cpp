#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string largestPalindromic(string num)
  {
    int n = num.length();
    if (n <= 1)
    {
      return num;
    }
    else
    {
    }
  }
};

int main()
{
  Solution sol;
  string num = "444947137";
  cout << sol.largestPalindromic(num) << endl;
}