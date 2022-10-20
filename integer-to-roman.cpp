#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string intToRoman(int num)
  {
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string thousands[] = {"", "M", "MM", "MMM"};

    return thousands[num / 1000] + hundreds[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
  }
};

int main()
{
  Solution sol;
  int num = 58;
  cout << sol.intToRoman(num) << endl;
  return 0;
}