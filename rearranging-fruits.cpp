#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution
{
public:
  long long minCost(vector<int> &v1, vector<int> &v2)
  {
    map<ll, ll> mp;
    int n = v1.size();
    ll x = v2[n - 1];

    for (int i = 0; i < n; i++)
    {
      mp[v1[i]]++;
      mp[v2[i]]--;
    }

    bool flag = false;
    v1.clear();
    v2.clear();

    ll minNumer = x;

    for (auto i : mp)
    {
      minNumer = min(minNumer, i.first);
      x = abs(i.second);

      if (x % 2)
        flag = true;

      x = i.second;

      if (x > 0)
      {
        x /= 2;

        while (x--)
          v1.push_back(i.first);
      }
      else if (x < 0)
      {
        x = abs(x) / 2;

        while (x--)
        {
          v2.push_back(i.first);
        }
      }
    }

    if (flag)
    {
      return -1;
    }

    reverse(v2.begin(), v2.end());

    ll ans = 0;

    for (int i = 0; i < v1.size(); i++)
      ans += min(2 * minNumer, 1ll * min(v1[i], v2[i]));

    return ans;
  }
};
