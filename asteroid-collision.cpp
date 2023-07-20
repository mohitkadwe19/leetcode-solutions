
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> asteroidCollision(vector<int> &asteroids)
  {
    vector<int> stack;

    for (auto i : asteroids)
    {
      while (!stack.empty() && stack.back() > 0 && i < 0)
      {
        int sum = i + stack.back();

        if (sum < 0)
          stack.pop_back();
        else if (sum > 0)
          i = 0;
        else
        {
          stack.pop_back();
          i = 0;
        }
      }

      if (i != 0)
      {
        stack.push_back(i);
      }
    }

    return stack;
  }
};

int main()
{
  vector<int> asteroids = {5, 10, -5};
  Solution sol;
  vector<int> ans = sol.asteroidCollision(asteroids);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}