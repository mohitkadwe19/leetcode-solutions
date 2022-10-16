#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string reverseWords(string s)
  {
    int n = s.size();
    string ans = "";
    int i = 0;
    for (int j = 0; j < n; j++)
    {
      if (s[j] == ' ')
      {
        for (int k = j - 1; k >= i; k--)
        {
          ans += s[k];
        }
        ans += ' ';
        i = j + 1;
      }
      if (j == n - 1)
      {
        for (int k = j; k >= i; k--)
        {
          ans += s[k];
        }
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  string str = "Let's take LeetCode contest";
  cout << s.reverseWords(str) << endl;
  return 0;
}