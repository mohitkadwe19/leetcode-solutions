#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int furthestDistanceFromOrigin(string moves)
  {
    int c = 0, l = 0, r = 0;
    for (int i = 0; i < moves.size(); i++)
    {
      if (moves[i] == '_')
      {
        c++;
      }
      if (moves[i] == 'R')
      {
        r++;
      }
      if (moves[i] == 'L')
      {
        l++;
      }
    }
    c += max(l, r) - min(l, r);
    return c;
  }
};

int main()
{
  Solution s;
  cout << s.furthestDistanceFromOrigin("RL_R_") << endl;
  return 0;
}