#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices, int fee)
  {
    int n = prices.size();
    int buy = -prices[0], sell = 0;
    for (int i = 1; i < n; i++)
    {
      buy = max(buy, sell - prices[i]);
      sell = max(sell, buy + prices[i] - fee);
    }
    return sell;
  }
};

int main()
{
  vector<int> prices = {1, 3, 2, 8, 4, 9};
  int fee = 2;
  Solution s;
  cout << s.maxProfit(prices, fee) << endl;
  return 0;
}