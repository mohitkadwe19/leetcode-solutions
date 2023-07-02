#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximumRequests(int n, vector<vector<int>> &requests)
  {
    int m = requests.size();
    int ans = 0;
    for (int i = 0; i < (1 << m); i++)
    {
      vector<int> count(n, 0);
      int cnt = 0;
      for (int j = 0; j < m; j++)
      {
        if (i & (1 << j))
        {
          count[requests[j][0]]--;
          count[requests[j][1]]++;
          cnt++;
        }
      }
      bool flag = true;
      for (int j = 0; j < n; j++)
      {
        if (count[j] != 0)
        {
          flag = false;
          break;
        }
      }
      if (flag)
        ans = max(ans, cnt);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> requests = {{0, 1}, {1, 0}, {0, 1}, {1, 2}, {2, 0}, {3, 4}};
  cout << s.maximumRequests(5, requests) << endl;
  return 0;
}