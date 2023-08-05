#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int accountBalanceAfterPurchase(int purchaseAmount)
  {
    int a = ((purchaseAmount + 5) / 10) * 10;
    int ans = 100 - a;
    return ans;
  }
};

int main()
{
  Solution s;
  int purchaseAmount = 9;
  cout << s.accountBalanceAfterPurchase(purchaseAmount) << endl;
  return 0;
}