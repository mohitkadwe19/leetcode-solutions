#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> plusOne(vector<int> &digits)
  {
    int n = digits.size();
    int carry = 1;
    for (int i = n - 1; i >= 0; i--)
    {
      int s = digits[i] + carry;
      digits[i] = s % 10;
      carry = s / 10;
    }
    if (carry != 0)
    {
      digits.push_back(carry);
      reverse(digits.begin(), digits.end());
    }

    return digits;
  }
};

int main()
{
  Solution sol;
  int arr[] = {1, 2, 3, 4};
  vector<int> digits = {1, 2, 3, 4};
  vector<int> res = sol.plusOne(digits);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
}