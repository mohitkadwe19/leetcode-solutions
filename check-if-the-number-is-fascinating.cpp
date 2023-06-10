#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isFascinating(int n)
  {
    string s = to_string(n) + to_string(n * 2) + to_string(n * 3);
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] != '1' + i)
        return false;
    }
    return true;
  }
};

int main()
{
  int n = 192;
  Solution sol;
  cout << sol.isFascinating(n) << endl;
  return 0;
}