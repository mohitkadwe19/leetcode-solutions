#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool haveConflict(vector<string> &event1, vector<string> &event2)
  {
    if (event2[0] <= event1[1] && event2[1] >= event1[0])
    {
      return true;
    }
    return false;
  }
};

int main()
{
  Solution sol;
  vector<string> event1 = {"2020-01-01 10:00:00", "2020-01-01 11:00:00"};
  vector<string> event2 = {"2020-01-01 10:30:00", "2020-01-01 11:30:00"};
  cout << sol.haveConflict(event1, event2) << endl;
  return 0;
}