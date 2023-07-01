#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void calculatingUnfairness(vector<int> &cookies, int cookiesIndex, int childCount, int &minUnfairness, vector<int> &sampleDistribution)
  {
    if (cookies.size() == cookiesIndex)
    {
      int maximumCookies = INT_MIN;
      for (auto count : sampleDistribution)
      {
        maximumCookies = max(maximumCookies, count);
      }
      minUnfairness = min(minUnfairness, maximumCookies);
      return;
    }
    for (int index = 0; index < childCount; index++)
    {
      sampleDistribution[index] += cookies[cookiesIndex];
      calculatingUnfairness(cookies, cookiesIndex + 1, childCount, minUnfairness, sampleDistribution);
      sampleDistribution[index] -= cookies[cookiesIndex];
    }
  }

  int distributeCookies(vector<int> &cookies, int k)
  {
    int minUnfairness = INT_MAX;
    vector<int> sampleDistribution(k, 0);
    calculatingUnfairness(cookies, 0, k, minUnfairness, sampleDistribution);
    return minUnfairness;
  }
};

int main()
{
  Solution s;
  vector<int> cookies = {1, 2, 3};
  int k = 3;
  cout << s.distributeCookies(cookies, k) << endl;
  return 0;
}