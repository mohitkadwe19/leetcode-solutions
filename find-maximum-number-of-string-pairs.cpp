#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximumNumberOfStringPairs(vector<string> &words)
  {
    unordered_map<string, int> m;
    int ans = 0;
    for (string &word : words)
    {
      sort(word.begin(), word.end());
      if (m[word] > 0)
      {
        m[word]--;
        ans++;
      }
      else
        m[word]++;
    }
    return ans;
    }
};

int main()
{
  Solution s;
  vector<string> words = {"ab", "ba", "cc"};
  int ans = s.maximumNumberOfStringPairs(words);
  cout << ans << endl;
  return 0;
}