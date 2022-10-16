#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
  stack<char> st;
  for (int i = 0; i < s.length(); i++)
  {
    char c = s[i];
    if (c == '{' || c == '[' || c == '}' || c == ']' || c == '(' || c == ')')
    {
      if (c == '{' || c == '[' || c == '(')
      {
        st.push(c);
      }
      else
      {
        if (st.empty())
        {
          return false;
        }
        else
        {
          char top = st.top();
          if (c == '}' && top != '{' || c == ']' && top != '[' || c == ')' && top != '(')
          {
            return false;
          }
          else
          {
            st.pop();
          }
        }
      }
    }
  }

  if (st.empty())
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  string s;
  cin >> s;
  if (isValid(s))
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}