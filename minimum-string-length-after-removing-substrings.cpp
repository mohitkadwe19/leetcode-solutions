#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minLength(string s)
  {
    int n = s.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
      char str = s[i];

      if (st.size() == 0)
      {
        st.push(str);
      }
      else
      {
        char c = st.top();

        if (str == 'B' || str == 'D')
        {
          if (str == 'B')
          {
            if (c == 'A')
            {
              st.pop();
            }
            else
            {
              st.push(str);
            }
          }
          else
          {
            if (c == 'C')
            {
              st.pop();
            }
            else
            {
              st.push(str);
            }
          }
        }
        else
        {
          st.push(str);
        }
      }
    }

    return st.size();
  }
};

int main()
{
  Solution s;
  cout << s.minLength("ccdaabcdbb") << endl;
  return 0;
}