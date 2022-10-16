#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool checkDistances(string s, vector<int> &distance)
  {
    // distance of similar letters should be greater than 0.
    int n = s.length();
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
      mp[s[i]].push_back(i);
    }

    for (auto &x : mp)
    {
      int a = x.second[0];
      int b = x.second[1];
      int c = x.first - 'a';
      if (abs(b - a) != (distance[c] + 1))
        return false;
    }
    return true;
  }
};

int main()
{
  Solution sol;
  string s = "aa";
  vector<int> distance = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  cout << sol.checkDistances(s, distance) << endl;
}