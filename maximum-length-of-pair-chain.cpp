#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findLongestChain(vector<vector<int>> &pairs)
  {
    sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });
    int ans = 1;
    int prev = pairs[0][1];
    for (int i = 1; i < pairs.size(); i++)
    {
      if (pairs[i][0] > prev)
      {
        ans++;
        prev = pairs[i][1];
      }
    }
    return ans;
    }
};

int main()
{
  Solution sol;
  vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
  cout << sol.findLongestChain(pairs) << endl;
  return 0;
}