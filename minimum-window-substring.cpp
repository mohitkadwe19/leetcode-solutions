#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string minWindow(string s, string t)
  {
    int n = s.size();
    int m = t.size();
    if (n == 0 || m == 0)
    {
      return "";
    }
    if (n < m)
    {
      return "";
    }
    int left = 0;
    int right = 0;
    int minLeft = 0;
    int minRight = 0;
    int minLen = INT_MAX;
    int count = 0;
    unordered_map<char, int> map;
    for (int i = 0; i < m; i++)
    {
      map[t[i]]++;
    }
    while (right < n)
    {
      if (map.find(s[right]) != map.end())
      {
        map[s[right]]--;
        if (map[s[right]] >= 0)
        {
          count++;
        }
        while (count == m)
        {
          if (right - left + 1 < minLen)
          {
            minLen = right - left + 1;
            minLeft = left;
            minRight = right;
          }
          if (map.find(s[left]) != map.end())
          {
            map[s[left]]++;
            if (map[s[left]] > 0)
            {
              count--;
            }
          }
          left++;
        }
      }
      right++;
    }
    if (minLen == INT_MAX)
    {
      return "";
    }
    return s.substr(minLeft, minLen);
  }
};

int main()
{
  Solution s;
  string str = "ADOBECODEBANC";
  string pat = "ABC";
  cout << s.minWindow(str, pat) << endl;
  return 0;
}