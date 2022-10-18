#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool checkIfPangram(string sentence)
  {
    unordered_map<char, int> mp;
    int n = sentence.length();
    for (int i = 0; i < n; i++)
    {
      mp[sentence[i]]++;
    }
    if (mp.size() == 26)
    {
      return true;
    }
    return false;
  }
};

int main()
{
  Solution s;
  string sentence = "leetcode";
  cout << s.checkIfPangram(sentence) << endl;
  return 0;
}