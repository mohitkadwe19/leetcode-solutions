#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool checkStrings(string s1, string s2)
  {
    int n = s1.size();
    string temp1;
    string temp2;
    string temp3;
    string temp4;
    for (int i = 0; i < n; i++)
    {
      if (i % 2)
      {
        temp1.push_back(s1[i]);
        temp2.push_back(s2[i]);
      }
      else
      {
        temp3.push_back(s1[i]);
        temp4.push_back(s2[i]);
      }
    }
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());
    sort(temp3.begin(), temp3.end());
    sort(temp4.begin(), temp4.end());
    if (temp1 == temp2 && temp3 == temp4)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

int main()
{
  Solution sol;
  string s1 = "abc";
  string s2 = "abcd";
  cout << sol.checkStrings(s1, s2) << endl;
  return 0;
}