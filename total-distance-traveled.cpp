#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int distanceTraveled(int mainTank, int additionalTank)
  {
    int i = 1, answer = 0;
    while (i <= mainTank)
    {
      answer += 10;
      if (i % 5 == 0 && additionalTank > 0)
      {
        mainTank++;
        additionalTank--;
      }
      i++;
    }
    return answer;
  }
};

int main()
{
  Solution sol;
  int mainTank = 5, additionalTank = 10;
  cout << sol.distanceTraveled(mainTank, additionalTank) << endl;
  return 0;
}