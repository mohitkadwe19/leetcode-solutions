#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findJudge(int n, vector<vector<int>> &trust)
  {
    vector<int> in(n + 1, 0), out(n + 1, 0);
    for (auto &t : trust)
    {
      out[t[0]]++;
      in[t[1]]++;
    }
    for (auto &t : trust)
    {
      cout << t[0] << " " << t[1] << endl;
    }
    for (int i = 1; i <= n; i++)
    {
      cout << in[i] << " " << out[i] << endl;
    }
    for (int i = 1; i <= n; i++)
    {
      if (in[i] == n - 1 && out[i] == 0)
        return i;
    }
    return -1;
  }
};

int main()
{
  Solution s;
  int n = 2;
  vector<vector<int>> trust{{1, 3}, {2, 3}};
  cout << s.findJudge(n, trust) << endl;
  return 0;
}