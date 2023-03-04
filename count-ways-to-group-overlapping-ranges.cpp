#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int power(int i, int j, int pow)
  {
    if (j == 0)
    {
      return 1;
    }
    if (j == 1)
    {
      return i;
    }

    long long answer = power(i, j / 2, pow);

    answer = (answer * answer) % pow;

    if (j % 2 == 1)
    {
      answer = (answer * i) % pow;
    }

    return answer;
  }
  int countWays(vector<vector<int>> &ranges)
  {
    sort(ranges.begin(), ranges.end());

    vector<vector<int>> ans;

    for (auto &i : ranges)
    {
      if (ans.size() == 0 or ans.back()[1] < i[0])
      {
        ans.push_back(i);
      }
      else
      {
        ans.back()[1] = max(ans.back()[1], i[1]);
      }
    }

    int sizeOfRange = ans.size();

    return power(2, sizeOfRange, 1e9 + 7);
  }
};
int main()
{
  vector<vector<int>> ranges = {{6, 10}, {2, 3}, {3, 4}};
  Solution obj;
  cout << obj.countWays(ranges) << endl;
  return 0;
}