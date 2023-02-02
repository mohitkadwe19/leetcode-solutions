#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isAlienSorted(vector<string> &words, string order)
  {
    int n = words.size();
    vector<int> orderMap(26);
    for (int i = 0; i < 26; i++)
    {
      orderMap[order[i] - 'a'] = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
      string word1 = words[i];
      string word2 = words[i + 1];
      int len1 = word1.length();
      int len2 = word2.length();
      int j = 0;
      while (j < len1 && j < len2)
      {
        if (word1[j] != word2[j])
        {
          if (orderMap[word1[j] - 'a'] > orderMap[word2[j] - 'a'])
          {
            return false;
          }
          break;
        }
        j++;
      }
      if (j == len2 && len1 > len2)
      {
        return false;
      }
    }
    return true;
  }
};

int main()
{
  vector<string> words = {"hello", "leetcode"};
  string order = "hlabcdefgijkmnopqrstuvwxyz";
  Solution s;
  cout << s.isAlienSorted(words, order) << endl;
  return 0;
}