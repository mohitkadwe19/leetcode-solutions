#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> topKFrequent(vector<string> &words, int k)
  {
    unordered_map<string, int> mp;
    for (auto &word : words)
    {
      mp[word]++;
    }
    // sort mp according to frequency
    vector<pair<string, int>> v;
    for (auto &it : mp)
    {
      v.push_back({it.first, it.second});
    }
    sort(v.begin(), v.end(), [](pair<string, int> &a, pair<string, int> &b)
         {
      if (a.second == b.second)
      {
        return a.first < b.first;
      }
      return a.second > b.second; });
    vector<string> ans;
    for (int i = 0; i < k; i++)
    {
      ans.push_back(v[i].first);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
  int k = 4;
  vector<string> ans = s.topKFrequent(words, k);
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}