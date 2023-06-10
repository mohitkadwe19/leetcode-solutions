#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestSemiRepetitiveSubstring(string s)
  {
    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
      for (int j = i + 1; j <= s.size(); j++)
      {
        string t = s.substr(i, j - i);

        int count = 0, flag = 0;

        for (int i = 0; i < t.size() - 1; i++)
        {
          if (t[i] == t[i + 1])
          {
            count++;
            if (count >= 2)
            {
              flag = 1;
            }
          }
        }

        if (!flag)
        {
          ans = max(ans, (int)t.size());
        }
      }
    }
    return ans;
  }
};

int main()
{
  string s = "52233";
  Solution sol;
  cout << sol.longestSemiRepetitiveSubstring(s) << endl;
  return 0;
}