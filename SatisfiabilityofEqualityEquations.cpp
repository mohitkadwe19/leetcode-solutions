#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int parent[26];

  int find(int x)
  {
    return parent[x] == x ? x : (parent[x] = find(parent[x]));
  }

  bool equationsPossible(vector<string> &equations)
  {
    for (int i = 0; i < 26; i++)
      parent[i] = i;

    for (auto it : equations)
    {
      if (it[1] == '=')
        parent[find(it[0] - 'a')] = find(it[3] - 'a');
    }

    for (auto it : equations)
    {
      if (it[1] == '!' && find(it[0] - 'a') == find(it[3] - 'a'))
        return false;
    }

    return true;
  }
};

int main()
{
  Solution sol;
  vector<string> equations = {"a==b", "b!=a"};
  cout << sol.equationsPossible(equations) << endl;
  return 0;
}