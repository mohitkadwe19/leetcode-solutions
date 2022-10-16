#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    unordered_map<char, char> m;
    unordered_map<char, char> n;
    if (s.size() != t.size())
    {
      return false;
    }
    else
    {
      for (int i = 0; i < s.size(); i++)
      {
        char x = s[i];
        char y = t[i];
        // check if the x is already present in map m
        if (m.find(x) != m.end())
        {
          // if the x is already present in map m, then check if the y is equal to the value of x in map m
          if (m[x] != y)
          {
            return false;
          }
        }
        else
        {
          if (n.find(y) != n.end())
          {
            return false;
          }
          else
          {
            m[x] = y;
            n[y] = true;
          }
        }
      }
    }
    return true;
  }
};

int main()
{
  Solution s;
  cout << s.isIsomorphic("egg", "add") << endl;
  return 0;
}