#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

class Solution
{
public:
  int numWays(vector<string> &words, string target)
  {
    int nt = (int)target.size();
    int ns = (int)words[0].size();

    vector<vector<int>> f(ns, vector<int>(26, 0));
    for (auto s : words)
    {
      for (int i = 0; i < ns; i++)
        f[i][s[i] - 'a']++;
    }

    vector<vector<long long>> dp(ns, vector<long long>(nt, -1));

    function<long long(int, int)> helper = [&](int posWord, int posTarget)
    {
      if (posTarget == nt)
        return 1ll;
      if (posWord == ns)
        return 0ll;
      if (dp[posWord][posTarget] != -1)
        return dp[posWord][posTarget];

      int p = target[posTarget] - 'a';
      long long res = 0;

      // take (posTarget)th character from (posWord)th character of strings in words
      res += (f[posWord][p] * helper(posWord + 1, posTarget + 1));
      res %= mod;

      // not take any character from (posWord)th character of strings in words
      res += (helper(posWord + 1, posTarget));
      res %= mod;

      dp[posWord][posTarget] = res % mod;
      return res;
    };

    return (int)helper(0, 0);
  }
};

int main()
{
  vector<string> words = {"acca", "bbbb", "caca"};
  string target = "aba";
  Solution s;
  cout << s.numWays(words, target) << endl;
  return 0;
}