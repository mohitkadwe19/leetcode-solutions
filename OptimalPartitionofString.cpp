#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int partitionString(string s)
  {
    map<char, int> mpp;
    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {

      mpp[s[i]]++;

      // if more than one char appears in single substring
      if (mpp[s[i]] > 1)
      {
        mpp.clear();
        ans++;
        i--;
      }
    }

    return ans + 1;
  }
};

int main()
{
  Solution s;
  string str = "abacaba";
  cout << s.partitionString(str) << endl;
  return 0;
}