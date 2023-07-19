#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end());
    int previous = 0;
    int ans = 0;
    for (int current = 1; current < intervals.size(); current++)
    {
      if (intervals[current][0] < intervals[previous][1])
      {
        ans++;

        if (intervals[current][1] <= intervals[previous][1])
        {
          previous = current;
        }
      }
      else
      {
        previous = current;
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  cout << s.eraseOverlapIntervals(intervals) << endl;
  return 0;
}