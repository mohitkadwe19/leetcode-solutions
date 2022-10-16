#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findArray(vector<int> &pref)
  {
    vector<int> ans;
    ans.push_back(pref[0]);
    for (int i = 1; i <= pref.size() - 1; i++)
    {
      ans.push_back(pref[i] ^ pref[i - 1]);
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> pref = {5, 2, 0, 3, 1};
  vector<int> ans = sol.findArray(pref);
  for (auto i : ans)
    cout << i << " ";
  cout << endl;
  return 0;
}