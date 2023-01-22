#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
  vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
  {
    bool ans = true;

    for (int i = 0; i < score.size(); i++)
    {
      if (ans)
      {
        ans = false;
        for (int j = 0; j < score.size() - 1; j++)
        {
          if (score[j][k] < score[j + 1][k])
          {
            score[j].swap(score[j + 1]);
            ans = true;
          }
        }
      }
      else
      {
        break;
      }
    }
    return score;
  }
};

int main()
{
}