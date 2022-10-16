#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
  int i = 0, j = s.size() - 1;
  while (i < j)
  {
    if (s[i] != s[j])
      return false;
    i++;
    j--;
  }
  return true;
}

class Solution
{
public:
  vector<vector<int>> palindromePairs(vector<string> &words)
  {
    vector<vector<int>> palindromePairs(words.size());
    for (int i = 0; i < words.size(); i++)
    {
      for (int j = 0; j < words.size(); j++)
      {
        if (i == j)
          continue;
        string word = words[i] + words[j];
        cout << word << " " << isPalindrome(word) << endl;
        if (isPalindrome(word))
        {
          palindromePairs[i].push_back(j);
        }
      }
    }
    return palindromePairs;
  }
};

int main()
{
  Solution sol;
  vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
  vector<vector<int>> ans = sol.palindromePairs(words);
  for (auto &w : ans)
  {
    cout << w[0] << " " << w[1] << " " << words[w[0]] << " " << words[w[1]] << endl;
  }
}