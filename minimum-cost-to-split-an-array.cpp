#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
  int minCost(vector<int> &nums, int k)
  {
    int size = nums.size();

    vector<vector<ll>> dp_1(size, vector<ll>(size, 0));

    for (ll i = 0; i < size; i++)
    {
      vector<ll> mp(size, 0);
      ll c = 0;
      for (ll j = i; j < size; j++)
      {
        if (mp[nums[j]] == 0)
        {
        }
        else if ((mp[nums[j]]) == 1)
        {
          c += 2;
        }
        else
        {
          c++;
        }
        mp[nums[j]]++;
        dp_1[i][j] = c;
      }
    }
    vector<ll> dp_2(size + 1, LLONG_MAX);
    dp_2[0] = 0;
    dp_2[1] = dp_1[0][0] + k;

    for (int i = 2; i <= size; i++)
    {
      dp_2[i] = dp_1[0][i - 1] + k;

      for (int j = i - 1; j >= 1; j--)
      {
        dp_2[i] = min(dp_2[i], dp_2[j] + dp_1[j][i - 1] + k);
      }
    }

    return dp_2[size];
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int k = 5;
  cout << s.minCost(nums, k) << endl;
  return 0;
}