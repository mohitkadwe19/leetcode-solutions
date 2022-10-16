#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minCost(string colors, vector<int> &neededTime)
  {
    int elementRemovalCount = 0;

    for (int i = 1; i < colors.size(); i++)
    {
      if (colors[i - 1] == colors[i])
      {
        if (neededTime[i - 1] < neededTime[i])
        {
          elementRemovalCount += neededTime[i - 1];
        }
        else
        {
          elementRemovalCount += neededTime[i];
          neededTime[i] = neededTime[i - 1];
        }
      }
    }
    return elementRemovalCount;
  }
};

int main()
{
  Solution s;
  string colors = "aabaa";
  vector<int> neededTime = {1, 2, 3, 4, 1};
  cout << s.minCost(colors, neededTime) << endl;
  return 0;
}