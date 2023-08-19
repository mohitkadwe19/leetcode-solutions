#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canMakeSubsequence(string str1, string str2)
  {
    if (str2.length() > str1.length())
    {
      return false;
    }
    int t = 0;
    for (int i = 0; i < str1.length() && t < str2.length(); i++)
    {
      if (str1[i] == str2[t])
      {
        t++;
      }
      else if (((str1[i] - 'a') + 1) % 26 + 'a' == str2[t])
      {
        t++;
      }
    }

    return t == str2.length();
  }
};

int main()
{
  Solution s;
  string str1 = "abc", str2 = "ad";
  cout << s.canMakeSubsequence(str1, str2) << endl;
  return 0;
}