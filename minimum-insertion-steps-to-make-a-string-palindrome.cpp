#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minInsertions(string s)
  {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (s[i] == s[j])
        {
          dp[i][j] = dp[i + 1][j - 1];
        }
        else
        {
          dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
      }
    }
    return dp[0][n - 1];
  }
};

int main()
{
  Solution s;
  cout << s.minInsertions("zzazz") << endl;
  cout << s.minInsertions("mbadm") << endl;
  cout << s.minInsertions("leetcode") << endl;
  cout << s.minInsertions("g") << endl;
  cout << s.minInsertions("no") << endl;
  return 0;
}