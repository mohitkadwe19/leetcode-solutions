#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double average(vector<int> &salary)
  {
    int min = INT_MAX, max = INT_MIN;
    double sum = 0;
    for (auto &s : salary)
    {
      if (s < min)
        min = s;
      if (s > max)
        max = s;
      sum += s;
    }
    return (sum - min - max) / (salary.size() - 2);
  }
};

int main()
{
  Solution solution;
  vector<int> salary = {4000, 3000, 1000, 2000};
  auto result = solution.average(salary);
  cout << result << endl;
}