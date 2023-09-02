#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canBeEqual(string s1, string s2)
  {
    unordered_map<char, int> count;
    int n = s1.length();
    if (s1 == s2)
    {
      return true;
    }

    for (int i = 0; i < n; i++)
    {
      count[s1[i]]++;
      count[s2[i]]--;
    }

    for (const auto &kv : count)
    {
      if (kv.second != 0)
      {
        return false;
      }
    }

    for (int i = 0; i < n - 2; i++)
    {
      if (s1[i] == s2[i + 2] && s1[i + 2] == s2[i])
      {
        return true;
      }
    }

    return false;
  }
};

int main()
{
  string s1 = "abcd", s2 = "cdab";
  Solution sol;
  cout << sol.canBeEqual(s1, s2) << endl;
  return 0;
}