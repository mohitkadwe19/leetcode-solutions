#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findAnagrams(string s, string p)
  {
    vector<int> ans;
    if (s.size() < p.size())
    {
      return ans;
    }
    int n = s.size(), m = p.size();
    vector<int> cnt(26, 0);
    for (int i = 0; i < m; i++)
    {
      cnt[p[i] - 'a']++;
    }
    int l = 0, r = 0, cnt1 = m;
    while (r < n)
    {
      if (cnt[s[r] - 'a'] > 0)
      {
        cnt1--;
      }
      cnt[s[r] - 'a']--;
      r++;
      if (cnt1 == 0)
      {
        ans.push_back(l);
      }
      if (r - l == m)
      {
        if (cnt[s[l] - 'a'] >= 0)
        {
          cnt1++;
        }
        cnt[s[l] - 'a']++;
        l++;
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  string s1 = "cbaebabacd";
  string s2 = "abc";
  vector<int> ans = s.findAnagrams(s1, s2);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}