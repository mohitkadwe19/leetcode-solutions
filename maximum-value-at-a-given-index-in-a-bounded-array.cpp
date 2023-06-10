#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxValue(int n, int index, int maxSum)
  {
    int left = index;
    int right = index;
    maxSum -= n;
    int ans = 1;
    while (maxSum >= (right - left + 1))
    {
      maxSum -= (right - left + 1);
      ans++;
      if (left > 0)
      {
        left--;
      }
      if (right < n - 1)
      {
        right++;
      }
      if (n == (right - left + 1))
      {
        break;
      }
    }
    ans += maxSum / n;
    return ans;
  }
};

int main()
{
  Solution s;
  cout << s.maxValue(4, 2, 6) << endl;
  cout << s.maxValue(6, 1, 10) << endl;
  cout << s.maxValue(3, 0, 815094800) << endl;
  cout << s.maxValue(3, 2, 18) << endl;
  cout << s.maxValue(5, 3, 35) << endl;

  return 0;
}