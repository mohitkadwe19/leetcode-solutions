#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> getWordsInLongestSubsequence(int n, vector<string> &words, vector<int> &groups)
  {
    int last = groups[0];
    vector<string> res;
    res.push_back(words[0]);

    for (int i = 1; i < n; i++){
      if(groups[i] != last){
        last = groups[i];
        res.push_back(words[i]);
      }
    }
    
    return res;
  }
};
int main()
{
  Solution s;
  vector<string> words = {"a", "b", "c"};
  vector<int> groups = {1, 1, 1};
  s.getWordsInLongestSubsequence(3, words, groups);
  for (auto &w : words)
    cout << w << " ";
  cout << endl;
  return 0;
}