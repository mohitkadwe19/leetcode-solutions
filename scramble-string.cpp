#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool solve(string a, string b, unordered_map<string, bool> &mp)
  {
    if (a == b) // Base Condition which are possible
      return true;
    int n = a.size();
    if (n <= 1)
      return false;

    string s = a;
    s += b;
    if (mp.find(s) != mp.end())
      return mp[s]; // If already present then return the previously calculated bool Value
    bool flag = false;
    for (int i = 1; i <= n - 1; i++)
    {
      bool c1 = (solve(a.substr(0, i), b.substr(n - i, i), mp) &&
                 solve(a.substr(i, n - i), b.substr(0, n - i), mp)); // Considering Swapping
      bool c2 = (solve(a.substr(0, i), b.substr(0, i), mp) &&
                 solve(a.substr(i, n - i), b.substr(i, n - i), mp)); // Not considering Swapping
      if (c1 || c2)
      { // If any of the Condition 1 OR 2 is TRUE return TRUE else return FALSE
        flag = true;
        break;
      }
    }
    return mp[s] = flag; // Storing the value of "s" = a+b
  }

  bool isScramble(string s1, string s2)
  {
    if (s1 == s2)
      return true;                  // No Need to check
    unordered_map<string, bool> mp; // To store the various string's that are generated
    return solve(s1, s2, mp);
  }
};

int main()
{
  Solution s;
  string s1 = "great";
  string s2 = "rgeat";
  cout << s.isScramble(s1, s2) << endl;
  return 0;
}