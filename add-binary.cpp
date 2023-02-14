#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string addBinary(string a, string b)
  {
    string result = "";
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    while (i >= 0 || j >= 0)
    {
      int sum = carry;
      if (i >= 0)
        sum += a[i--] - '0';
      if (j >= 0)
        sum += b[j--] - '0';
      result = to_string(sum % 2) + result;
      carry = sum / 2;
    }
    if (carry != 0)
    {
      result = to_string(carry) + result;
    }
    return result;
  }
};

int main()
{
  string a = "11", b = "1";
  Solution s;
  cout << s.addBinary(a, b) << endl;
  return 0;
}