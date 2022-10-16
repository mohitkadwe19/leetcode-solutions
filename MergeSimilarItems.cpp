#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
  {
    vector<vector<int>> ans;

    map<int, int> m;

    for (auto &x : items1)
    {

      m[x[0]] += x[1];
    }

    for (auto &x : items2)
    {

      m[x[0]] += x[1];
    }

    for (auto x : m)
    {

      ans.push_back({x.first, x.second});
    }

    return ans;
  }
};

int main()
{
  vector<vector<int>> items1 = {{1, 3}, {2, 3}, {3, 4}, {4, 5}};
  vector<vector<int>> items2 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  Solution s;
  vector<vector<int>> ans = s.mergeSimilarItems(items1, items2);
  for (auto i : ans)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
