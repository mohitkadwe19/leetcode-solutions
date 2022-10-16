#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void reverseString(vector<char> &s)
  {
    int i = 0, j = s.size() - 1;
    while (i <= j)
    {
      char temp = s[i];
      s[i] = s[j];
      s[j] = temp;
      i++;
      j--;
    }
    return;
  }
};

int main()
{
  Solution sol;
  vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  sol.reverseString(s);
  return 0;
}