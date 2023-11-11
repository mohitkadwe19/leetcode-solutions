#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  long long distributeCandies(int n, int limit)
  {
    auto comb_1 = [](int n)
    {
      return 1LL * n * (n - 1) / 2;
    };
    if (n > 3 * limit)
    {
      return 0;
    }
    long long ans = comb_1(n + 2);
    if (n > limit)
    {
      ans -= 3 * comb_1(n - limit + 1);
    };
    if (n - 2 >= 2 * limit)
    {
      ans += 3 * comb_1(n - 2 * limit);
    };
    return ans;
  }
};

int main(){
  Solution sol;
  cout << sol.distributeCandies(7, 4) << endl;
  cout << sol.distributeCandies(10, 3) << endl;
  cout << sol.distributeCandies(1000000000, 100000) << endl;
  return 0;
}