#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long putMarbles(vector<int> &weights, int k)
  {
    vector<int> v;
    for (int i = 0; i < weights.size() - 1; i++)
      v.push_back(weights[i] + weights[i + 1]);
    sort(v.begin(), v.end());
    int i = 0, j = weights.size() - 2;
    long long ans = 0;
    while (i < k - 1)
    {
      ans += (v[j] - v[i]);
      i++, j--;
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> weights = {2, 4, 3, 5, 1};
  int k = 3;
  cout << sol.putMarbles(weights, k) << endl;
  return 0;
}