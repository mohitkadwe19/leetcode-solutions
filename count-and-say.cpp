#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string countAndSay(int n)
  {
    if (n == 0)
    {
      return " ";
    }
    if (n == 1)
    {
      return "1";
    }

    else
    {
      string s = countAndSay(n - 1);
      string ans = "";
      int count = 1;
      for (int i = 0; i < s.length(); i++)
      {
        if (s[i] == s[i + 1])
        {
          count++;
        }
        else
        {
          ans += to_string(count) + s[i];
          count = 1;
        }
      }
      return ans;
    }
  }
};

int main()
{
  Solution sol;
  int n = 4;
  cout << sol.countAndSay(n) << endl;
  return 0;
}