#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maxRunTime(int n, vector<int> &batteries)
  {
    sort(batteries.begin(), batteries.end(), greater<int>());
    long long extraTime = 0;
    int diff;

    for (int i = n; i < batteries.size(); i++)
    {
      extraTime += batteries[i];
    }
    int updatedMin = batteries[n - 1];
    for (int i = 1; i < n; i++)
    {
      diff = i * (batteries[n - i - 1] - batteries[n - i]);
      cout << diff << endl;
      if (!diff)
        continue;
      if (diff < extraTime)
      {
        extraTime -= diff;
        updatedMin = batteries[n - i - 1];
      }
      else
      {
        updatedMin += extraTime / i;
        extraTime = extraTime % i;
        break;
      }
    }
    return updatedMin + extraTime / n;
  }
};

int main()
{
  int n = 2;
  vector<int> batteries = {1, 2};
  Solution s;
  cout << s.maxRunTime(n, batteries);
  return 0;
}
