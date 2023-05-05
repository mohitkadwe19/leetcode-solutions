#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isVowel(char c)
  {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  }
  int maxVowels(string s, int k)
  {
    int n = s.size();
    int i = 0, j = 0;
    int ans = 0;
    int cnt = 0;
    while (j < n)
    {
      if (isVowel(s[j]))
        cnt++;
      if (j - i + 1 < k)
        j++;
      else if (j - i + 1 == k)
      {
        ans = max(ans, cnt);
        if (isVowel(s[i]))
          cnt--;
        i++;
        j++;
      }
    }
    return ans;
  }
};

int main()
{
  string s = "abciiidef";
  int k = 3;
  Solution sol;
  return 0;
}
