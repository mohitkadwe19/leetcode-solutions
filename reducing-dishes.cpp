#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxSatisfaction(vector<int> &satisfaction)
  {
    sort(satisfaction.begin(), satisfaction.end());
    int n = satisfaction.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int sum = 0;
      for (int j = i; j < n; j++)
      {
        sum += (j - i + 1) * satisfaction[j];
      }
      ans = max(ans, sum);
    }
    return ans;
  }
};

int main()
{
  vector<int> satisfaction = {-1, -8, 0, 5, -9};
  Solution obj;
  cout << obj.maxSatisfaction(satisfaction) << endl;
  return 0;
}