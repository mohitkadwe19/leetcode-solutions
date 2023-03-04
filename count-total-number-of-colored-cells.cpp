#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long coloredCells(int n)
  {
    long long cells = 1ll * (n) * (n) + 1ll * (n - 1) * (n - 1);
    return cells;
  }
};

int main()
{
  int n;
  cin >> n;
  Solution obj;
  cout << obj.coloredCells(n) << endl;
  return 0;
}