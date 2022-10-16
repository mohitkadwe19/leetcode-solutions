#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  string toHex(int num)
  {
    string hex = "0123456789abcdef";
    unsigned int n = num;
    string ans = "";
    if (n == 0)
    {
      return "0";
    }
    else
    {
      while (n > 0)
      {
        int k = n % 16;
        ans += hex[k];
        n = n / 16;
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
  }
};
int main()
{
  int num = 26;
  Solution s;
  cout << s.toHex(num) << endl;
}
