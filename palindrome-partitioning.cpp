#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPalindrome(string s)
  {
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }
  void solve(string s, int index, vector<string> &temp, vector<vector<string>> &ans)
  {
    if (index == s.size())
    {
      ans.push_back(temp);
      return;
    }
    for (int i = index; i < s.size(); i++)
    {
      if (isPalindrome(s.substr(index, i - index + 1)))
      {
        temp.push_back(s.substr(index, i - index + 1));
        solve(s, i + 1, temp, ans);
        temp.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s)
  {
    vector<vector<string>> ans;
    vector<string> temp;
    solve(s, 0, temp, ans);
    return ans;
  }
};

int main()
{
  string s = "aab";
  Solution obj;
  vector<vector<string>> ans = obj.partition(s);
  for (auto i : ans)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}