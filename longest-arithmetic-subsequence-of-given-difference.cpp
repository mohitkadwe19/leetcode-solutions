#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestSubsequence(vector<int> &arr, int difference)
  {
    map<int, int> m;
    for (int i = 0; i < arr.size(); i++)
    {
      if (m[arr[i] - difference] > 0)
      {
        m[arr[i]] = 1 + m[arr[i] - difference];
      }
      else
      {
        m[arr[i]] = 1;
      }
    }
    int maxi = 1;
    for (auto i : m)
    {
      maxi = max(maxi, i.second);
    }
    return maxi;
  }
};

int main()
{
  Solution s;
  vector<int> arr = {1, 3, 5, 7};
  cout << s.longestSubsequence(arr, 2);
  return 0;
}