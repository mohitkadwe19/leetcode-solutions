#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool stp(int i, string s, int n, int sum)
  {
    if (i == s.length())
    {
      if (sum == n)
      {
        return true;
      }
      return false;
    }

    for (int ind = i; ind < s.length(); ind++)
    {
      if (stp(ind + 1, s, n, sum + std::stoi(s.substr(i, ind - i + 1))))
      {
        return true;
      }
    }

    return false;
  }

  bool isPunishment(int n)
  {
    if (stp(0, to_string(n * n), n, 0))
    {
      return true;
    }
    return false;
  }

  int punishmentNumber(int n)
  {
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
      if (isPunishment(i))
      {
        ans += i * i;
      }
    }

    return ans;
  }
};

int main()
{
  Solution s;
  int n = 10;
  cout << s.punishmentNumber(n) << endl;
  return 0;
}