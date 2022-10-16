#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isSubsequence(string s, string t)
  {

    int i = 0, j = 0;
    while (i < s.size() && j < t.size())
    {
      if (s[i] == t[j])
      {
        i++;
      }
      j++;
      cout << i << " " << j << endl;
    }

    if (i == s.size())
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

int main()
{
  string s = "abc";
  string t = "ahbgdc";
  Solution sol;
  cout << sol.isSubsequence(s, t) << endl;
  return 0;
}