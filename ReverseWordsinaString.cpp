#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string reverseWords(string s)
  {
    stack<string> st;
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == ' ')
      {
        if (temp != "")
        {
          st.push(temp);
          temp = "";
        }
      }
      else
      {
        temp += s[i];
      }
    }
    if (temp != "")
    {
      st.push(temp);
    }
    string ans = "";
    while (!st.empty())
    {
      ans += st.top();
      st.pop();
      if (!st.empty())
      {
        ans += " ";
      }
    }
    return ans;

    // second 2 pointer approach
    // string res = "";
    // int i = 0;
    // while (i < s.length())
    // {
    //   while (i < s.length() && s[i] == ' ')
    //   {
    //     i++;
    //   }
    //   if (i >= s.length())
    //   {
    //     break;
    //   }
    //   int j = i + 1;
    //   while (j < s.length() && s[j] != ' ')
    //   {
    //     j++;
    //   }
    //   string t = s.substr(i, j - i);
    //   if (res.length() == 0)
    //   {
    //     res = t;
    //   }
    //   else
    //   {
    //     res = t + " " + res;
    //   }
    //   i = j + 1;
    // }
    // return res;
  }
};

int main()
{
  Solution sol;
  string s = "  hello world  ";
  cout << sol.reverseWords(s) << endl;
  return 0;
}