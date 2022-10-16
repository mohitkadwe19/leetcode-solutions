#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int myAtoi(string s)
  {
    // remove leading spaces
    int i = 0;
    while (i < s.size() && s[i] == ' ')
      i++;
    if (i == s.size())
    {
      return 0;
    }
    // check sign
    int sign = 1;
    if (s[i] == '+')
      i++;
    else if (s[i] == '-')
    {
      sign = -1;
      i++;
    }
    // check overflow
    int res = 0;
    while (i < s.size() && s[i] >= '0' && s[i] <= '9')
    {
      if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > 7))
        return sign == 1 ? INT_MAX : INT_MIN;
      res = res * 10 + s[i++] - '0';
    }
    return res * sign;
  }
};

int main()
{
  string s = "4193 with words";
  // cin >> s;
  Solution sol;
  cout << sol.myAtoi(s) << endl;
  return 0;
}