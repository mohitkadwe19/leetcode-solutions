#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string convertToTitle(int columnNumber)
  {
    string ans = "";
    while (columnNumber > 0)
    {
      columnNumber -= 1;
      ans += (char)('A' + columnNumber % 26);
      columnNumber /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  Solution s;
  cout << s.convertToTitle(1) << endl;
  cout << s.convertToTitle(28) << endl;
  cout << s.convertToTitle(701) << endl;
  cout << s.convertToTitle(2147483647) << endl;
  return 0;
}