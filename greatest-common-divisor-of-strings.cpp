#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string gcdOfStrings(string str1, string str2)
  {
    if (str1 + str2 != str2 + str1)
    {
      return "";
    }
    return str1.substr(0, __gcd(str1.size(), str2.size()));
  }
};

int main()
{
  string str1 = "ABCABC", str2 = "ABC";
  Solution s;
  cout << s.gcdOfStrings(str1, str2) << endl;
  return 0;
}