#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(string &s, unordered_map<string, int> &mp, vector<int> &dp, int idx)
  {
    if (idx >= s.size())
      return 0;
    if (dp[idx] != -1)
      return dp[idx];

    string currStr = "";
    int ans = s.size();

    for (int cutIdx = idx; cutIdx < s.size(); cutIdx++)
    {
      currStr.push_back(s[cutIdx]);
      // Check if currStr exists in the dictionary
      int count = ((mp.count(currStr)) ? 0 : currStr.size()) + solve(s, mp, dp, cutIdx + 1);
      ans = min(ans, count);
    }
    return dp[idx] = ans;
  }

  int minExtraChar(string s, vector<string> &dictionary)
  {
    vector<int> dp(s.size(), -1);
    unordered_map<string, int> mp;
    for (string &word : dictionary)
      mp[word]++;
    return solve(s, mp, dp, 0);
  }
};

int main()
{
  string s = "leetscode";
  vector<string> dictionary = {"leet", "code", "leetcode"};
  Solution sol;
  cout << sol.minExtraChar(s, dictionary) << endl;
  return 0;
}