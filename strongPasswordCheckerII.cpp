#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool strongPasswordCheckerII(string password)
  {
    // It has at least 8 characters.
    // It contains at least one lowercase letter.
    // It contains at least one uppercase letter.
    // It contains at least one digit.
    // It contains at least one special character.
    // The special characters are the characters in the following string : "!@#$%^&*()-+".It does not contain 2 of the same character in adjacent positions(i.e., "aab" violates this condition, but "aba" does not ).
    // It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not)

    int n = password.size();
    if (n < 8)
    {
      return false;
    }

    int lower = 0, upper = 0, digit = 0, special = 0, same = 0;
    for (int i = 0; i < n; i++)
    {
      if (i > 0 && password[i] == password[i - 1])
      {
        same++;
      }

      if (password[i] >= 'a' && password[i] <= 'z')
      {
        lower++;
      }
      if (password[i] >= 'A' && password[i] <= 'Z')
      {
        upper++;
      }
      if (password[i] >= '0' && password[i] <= '9')
      {
        digit++;
      }
      if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '+')
      {
        special++;
      }
    }

    if (same > 0)
    {
      return false;
    }

    if (lower > 0 && upper > 0 && digit > 0 && special > 0)
    {
      return true;
    }

    return false;
  }
};
int main()
{
  Solution sol;
  string password = "11A!A!Aa";
  cout << sol.strongPasswordCheckerII(password) << endl;
}