#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numSimilarGroups(vector<string> &strs)
  {
    int n = strs.size();
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
      parent[i] = i;

    function<int(int)> find = [&](int x)
    {
      return parent[x] == x ? x : parent[x] = find(parent[x]);
    };

    function<void(int, int)> unite = [&](int x, int y)
    {
      x = find(x);
      y = find(y);
      if (x != y)
        parent[x] = y;
    };

    function<bool(string, string)> similar = [&](string a, string b)
    {
      int cnt = 0;
      for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i] && ++cnt > 2)
          return false;
      return true;
    };

    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (similar(strs[i], strs[j]))
          unite(i, j);

    unordered_set<int> s;
    for (int i = 0; i < n; i++)
      s.insert(find(i));
    return s.size();
  }
};

int main()
{
  Solution sol;
  vector<string> strs = {"tars", "rats", "arts", "star"};
  cout << sol.numSimilarGroups(strs) << endl;
  return 0;
}
