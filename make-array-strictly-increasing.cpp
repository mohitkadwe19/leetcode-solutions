#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
  {
    int n = arr1.size();
    sort(arr2.begin(), arr2.end());
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      vector<int> temp(n + 1, INT_MAX);
      for (int j = 0; j <= i; j++)
      {
        if (arr1[i] > dp[j])
        {
          temp[j] = min(temp[j], arr1[i]);
        }
        auto it = upper_bound(arr2.begin(), arr2.end(), dp[j]);
        if (it != arr2.end())
        {
          temp[j + 1] = min(temp[j + 1], *it);
        }
      }
      dp = temp;
    }
    for (int i = 0; i <= n; i++)
    {
      if (dp[i] != INT_MAX)
        return i;
    }
    return -1;
  }
};

int main()
{
  Solution sol;
  vector<int> arr1 = {1, 5, 3, 6, 7};
  vector<int> arr2 = {1, 3, 2, 4};
  cout << sol.makeArrayIncreasing(arr1, arr2) << endl;
  return 0;
}