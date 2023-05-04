#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string predictPartyVictory(string senate)
  {
    int n = senate.size();
    queue<int> q1, q2;
    for (int i = 0; i < n; i++)
    {
      if (senate[i] == 'R')
        q1.push(i);
      else
        q2.push(i);
    }
    while (!q1.empty() && !q2.empty())
    {
      int r_index = q1.front();
      int d_index = q2.front();
      q1.pop();
      q2.pop();
      if (r_index < d_index)
        q1.push(r_index + n);
      else
        q2.push(d_index + n);
    }
    return q1.size() > q2.size() ? "Radiant" : "Dire";
  }
};

int main()
{
  Solution solution;
  string senate = "RD";
  auto result = solution.predictPartyVictory(senate);
  cout << result;
}