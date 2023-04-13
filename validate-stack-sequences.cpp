#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
  {
    stack<int> s;
    int i = 0;
    for (int x : pushed)
    {
      s.push(x);
      while (!s.empty() && s.top() == popped[i])
      {
        s.pop();
        i++;
      }
    }
    return s.empty();
  }
};

int main()
{
  Solution s;
  vector<int> pushed = {1, 2, 3, 4, 5};
  vector<int> popped = {4, 5, 3, 2, 1};
  cout << s.validateStackSequences(pushed, popped) << endl;
  return 0;
}