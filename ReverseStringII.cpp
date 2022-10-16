#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string reverseStr(string s, int k)
  {
    string result = s;
    int n = s.size();

    for (int i = 0; i < n; i += 2 * k)
    {
      if (i + k <= n)
      {
        reverse(result.begin() + i, result.begin() + i + k);
      }
      else
      {
        reverse(result.begin() + i, result.end());
      }
    }
    return result;
  }
};

int main()
{
  Solution sol;
  string s = "abcdefg";
  cout << sol.reverseStr(s, 2) << endl;
  return 0;
}