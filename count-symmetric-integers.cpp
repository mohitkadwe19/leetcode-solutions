#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isSymmetric(int x)
  {
    string s = to_string(x);
    int n = s.length() / 2;
    string first_half = s.substr(0, n);
    string second_half = s.substr(s.length() - n);
    int sum_first_half = 0;
    int sum_second_half = 0;
    for (char digit : first_half)
    {
      sum_first_half += digit - '0';
    }
    for (char digit : second_half)
    {
      sum_second_half += digit - '0';
    }
    return sum_first_half == sum_second_half;
  }
  int countSymmetricIntegers(int low, int high)
  {
    int count = 0;
    for (int x = low; x <= high; x++)
    {
      if (to_string(x).length() % 2 == 0 && isSymmetric(x))
      {
        count++;
      }
    }
    return count;
  }
};

int main()
{
  int low = 1, high = 100;
  Solution sol;
  cout << sol.countSymmetricIntegers(low, high) << endl;
  return 0;
}