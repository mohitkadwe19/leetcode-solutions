#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findTheLongestBalancedSubstring(string s)
  {
    int ans = 0, n = s.size();

    for (int i = 0; i < n; i++)
    {
      int j = i;
      int count1 = 0, count2 = 0;
      for (; j < n; j++)
      {
        if (s[j] == '0')
        {
          count1++;
        }
        if (s[j] == '1')
        {
          break;
        }
      }

      int k = j;

      for (; k < n; k++)
      {
        if (s[k] == '1')
        {
          count2++;
        }
        if (s[k] == '0')
        {
          break;
        }
        if (count1 == count2)
        {
          ans = max(ans, (k - i + 1));
        }
      }
    }

    return ans;
  }
};

int main()
{
  string s;
  cin >> s;
  Solution obj;
  cout << obj.findTheLongestBalancedSubstring(s) << endl;
  return 0;
}