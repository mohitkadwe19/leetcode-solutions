#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int hardestWorker(int n, vector<vector<int>> &logs)
  {
    int difference = logs[0][1] - 0, ans = 0, Id = logs[0][0];

    for (int i = 1; i <= logs.size() - 1; i++)
    {
      ans = logs[i][1] - logs[i - 1][1];

      if (ans == difference)
      {
        Id = min(Id, logs[i][0]);
      }

      if (ans > difference)
      {
        difference = ans;
        Id = logs[i][0];
      }
    }
    return Id;
  }
};

int main()
{
  Solution sol;
  int n = 10;
  vector<vector<int>> logs = {{0, 3}, {2, 5}, {0, 9}, {1, 15}};
  cout << sol.hardestWorker(n, logs) << endl;
  return 0;
}