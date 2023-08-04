#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool wordBreak(string s, vector<string> &wordDict)
  {

    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++)
    {
      for (int j = i - 1; j >= 0; j--)
      {
        if (dp[j])
        {
          string word = s.substr(j, i - j);
          if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end())
          {
            dp[i] = true;
            break;
          }
        }
      }
    }
    return dp[n];
  }
};

int main()
{
  Solution s;
  string str = "leetcode";
  vector<string> wordDict;
  wordDict.push_back("leet");
  wordDict.push_back("code");
  cout << s.wordBreak(str, wordDict);
  return 0;
}