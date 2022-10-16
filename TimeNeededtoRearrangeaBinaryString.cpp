#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int secondsToRemoveOccurrences(string s)
  {
    int i, j, count = 0;
    int loop = 1;
    while (loop)
    {
      loop = 0;
      for (j = 0; j < s.size() - 1; j++)
      {
        if (s[j] == '0' && s[j + 1] == '1')
        {
          swap(s[j], s[j + 1]);
          j++;
          loop = 1;
        }
      }
      count += loop;
    }
    return count;
  }
};

int main()
{
  Solution sol;
  string s = "0110101";
  cout << sol.secondsToRemoveOccurrences(s) << endl;
}