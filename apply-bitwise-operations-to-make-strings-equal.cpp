#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool makeStringsEqual(string s, string target)
  {
    if (s == target)
    {
      return true;
    }

    int target1 = 0, s1 = 0;

    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == '1')
      {
        target1++;
      }
      if (target[i] == '1')
      {
        s1++;
      }
    }

    if ((target1 >= 1 && s1 == 0) || (target1 == 0 && s1 >= 1))
    {
      return false;
    }
    return true;
  }
};

int main()
{
  Solution s;
  string s1 = "abc";
  string s2 = "cde";
  cout << s.makeStringsEqual(s1, s2) << endl;
  return 0;
}