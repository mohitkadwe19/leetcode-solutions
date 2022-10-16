#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestPalindrome(string s)
  {
    int ans = 0;
    unordered_map<char, int> m;
    for (char c : s)
    {
      m[c]++;
    }

    for (auto p : m)
    {
      cout << p.second << " ";
      ans += p.second / 2 * 2;
    }
    return ans < s.size() ? ans + 1 : ans;
  }
};

int main()
{
  Solution s;
  string str = "abccccdd";
  cout << s.longestPalindrome(str) << endl;
  return 0;
}
