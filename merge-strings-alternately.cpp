#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string mergeAlternately(string word1, string word2)
  {
    string res = "";
    int i = 0, j = 0;
    while (i < word1.size() && j < word2.size())
    {
      res += word1[i++];
      res += word2[j++];
    }
    while (i < word1.size())
    {
      res += word1[i++];
    }
    while (j < word2.size())
    {
      res += word2[j++];
    }
    return res;
  }
};

int main()
{
  string word1 = "abc", word2 = "pqr";
  Solution obj;
  cout << obj.mergeAlternately(word1, word2) << endl;
  return 0;
}