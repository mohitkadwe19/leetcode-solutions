#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
  // convert all upper case to lower case
  for (int i = 0; i < s.length(); i++)
  {
    s[i] = tolower(s[i]);

    // remove all non-alphanumeric characters
    if (!isalnum(s[i]))
    {
      s.erase(i, 1);
      i--;
    }
  }
  // check if the string is a palindrome
  int i = 0;
  int j = s.length() - 1;
  while (i < j)
  {
    if (s[i] != s[j])
    {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

int main()
{
  // take space separated string as input
  char s;
  cin >> s;
  cout << isPalindrome(s) << endl;
}