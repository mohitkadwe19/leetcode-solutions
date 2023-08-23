#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string reorganizeString(string s)
  {
    string ans;
    map<char, int> mp;
    for (auto it : s)
      mp[it]++;
    priority_queue<pair<int, int>> pq;
    int size = 0;
    for (auto it : mp)
    {
      pq.push({it.second, it.first});
    }
    while (pq.size() >= 2)
    {
      int cnt1 = pq.top().first;
      int ch1 = pq.top().second;
      pq.pop();
      int cnt2 = pq.top().first;
      int ch2 = pq.top().second;
      pq.pop();
      mp[ch1]--;
      mp[ch2]--;
      ans.push_back(ch1);
      ans.push_back(ch2);
      if (mp[ch1] > 0)
        pq.push({mp[ch1], ch1});
      if (mp[ch2] > 0)
        pq.push({mp[ch2], ch2});
    }

    if (pq.size() == 1)
    {
      if (pq.top().first > 1)
        return "";
      else
        ans.push_back(pq.top().second);
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  cout << sol.reorganizeString("aab") << endl;
  return 0;
}