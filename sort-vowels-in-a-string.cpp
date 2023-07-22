#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string sortVowels(string s)
  {
    int n = s.size();
    string t = "";
    for (int i = 0; i < n; i++)
    {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
          s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
      {
        t += s[i];
      }
    }
    sort(t.begin(), t.end());
    int j = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
          s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
      {
        s[i] = t[j];
        j++;
      }
    }

    return s;
  }
};

int main()
{
  Solution s;
  string str = "leetcode";
  cout << s.sortVowels(str) << endl;
  return 0;
}