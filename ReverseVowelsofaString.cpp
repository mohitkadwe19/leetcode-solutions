#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string reverseVowels(string s)
  {
    int n = s.length();
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
      {
        if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')
        {
          swap(s[i], s[j]);
          i++;
          j--;
        }
        else
        {
          j--;
        }
      }
      else
      {
        i++;
      }
    }
    return s;
  }
};

int main()
{
  Solution sol;
  string s = "leetcode";
  cout << sol.reverseVowels(s) << endl;
}