#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isRepeating(string &s, string &pattern)
  {
    int n = s.size();
    int m = pattern.size();
    if (n % m != 0 || n == m)
    {
      return false;
    }
    int x = 0;
    while (x < n)
    {
      string subS = s.substr(x, m);
      if (pattern != subS)
      {
        return false;
      }
      else
      {
        x += m;
      }
    }
    return true;
  }
  bool repeatedSubstringPattern(string s)
  {
    int i = 0;
    int j = 0;
    string pattern = "";
    while (j < s.size())
    {
      pattern = s.substr(0, j + 1);
      if (isRepeating(s, pattern))
      {
        return true;
      }
      j++;
    }
    return false;
  }
};

int main()
{
  string s = "abab";
  Solution sol;
  cout << sol.repeatedSubstringPattern(s) << endl;
  return 0;
}