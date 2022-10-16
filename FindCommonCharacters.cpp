#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> commonChars(vector<string> &words)
  {
    vector<string> res;
    vector<int> minfreq(26, INT_MAX);
    for (string word : words)
    {
      vector<int> freq(26, 0);
      for (char c : word)
        freq[c - 'a']++;
      for (int i = 0; i < 26; i++)
        minfreq[i] = min(minfreq[i], freq[i]);
    }
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < minfreq[i]; j++)
        res.push_back(string(1, i + 'a'));
    return res;
  }
};

int main()
{
  Solution s;
  string str[] = {"bella", "label", "roller"};
  vector<string> words(str, str + sizeof(str) / sizeof(str[0]));
  vector<string> res = s.commonChars(words);
  for (auto i : res)
    cout << i << " ";
  return 0;
}