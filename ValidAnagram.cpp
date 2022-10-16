#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    if (s.size() != t.size())
      return false;
    int count[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
      count[s[i] - 'a']++;
      count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
      cout << count[i] << endl;
      if (count[i] != 0)
        return false;
    }
    return true;
  }
};

int main()
{
  Solution s;
  cout << s.isAnagram("rat", "car") << endl;
  return 0;
}