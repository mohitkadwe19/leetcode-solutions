#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> sortPeople(vector<string> &names, vector<int> &heights)
  {
    vector<string> ans;
    map<int, string> mp;
    for (int i = 0; i < heights.size(); i++)
    {
      mp[heights[i]] = names[i];
    }
    for (auto x : mp)
    {
      ans.push_back(x.second);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  Solution sol;
  vector<string> names = {"Mary", "John", "Emma"};
  vector<int> heights = {180, 165, 170};
  sol.sortPeople(names, heights);
  return 0;
}