#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxLength(vector<string> &arr)
  {
    int n = arr.size(), ans = 0;
    vector<int> dp(1, 0);
    for (int i = 0; i < n; i++)
    {
      int mask = 0;
      for (char c : arr[i])
      {
        int bit = c - 'a';
        if (mask & (1 << bit))
        {
          mask = 0;
          break;
        }
        mask |= (1 << bit);
      }
      if (mask == 0)
      {
        continue;
      }

      int size = dp.size();

      for (int j = 0; j < size; j++)
      {
        int m = dp[j];
        if (m & mask)
        {
          continue;
        }
        dp.push_back(m | mask);
        ans = max(ans, __builtin_popcount(m | mask));
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<string> arr = {"un", "iq", "ue"};
  cout << s.maxLength(arr) << endl;
  return 0;
}