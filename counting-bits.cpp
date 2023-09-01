#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> countBits(int n)
  {
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
      ans[i] = ans[i & (i - 1)] + 1;
    return ans;
  }
};

int main()
{
  Solution sol;
  int n = 2;
  vector<int> ans = sol.countBits(n);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}