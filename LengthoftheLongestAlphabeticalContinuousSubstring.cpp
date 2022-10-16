#include <bits/stdc++.h>
#include <math.h>
using namespace std;

class Solution
{
public:
  int longestContinuousSubstring(string s)
  {
    int n = s.length();
    int maxNumber = 1;
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
      if (s[i] == (s[i - 1] + 1))
      {
        ans++;
        maxNumber = max(ans, maxNumber);
      }
      else
      {
        ans = 1;
      }
    }
    maxNumber = max(ans, maxNumber);
    return maxNumber;
  }
};

int main()
{
  Solution sol;
  string s = "abcf";
  cout << sol.longestContinuousSubstring(s) << endl;
}