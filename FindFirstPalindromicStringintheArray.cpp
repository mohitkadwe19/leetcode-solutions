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

  string firstPalindrome(vector<string> &words)
  {
    // check if the array is empty
    if (words.empty())
    {
      return "";
    }
    else
    {
      // check if the string element of vector is palindrome or not
      for (int i = 0; i < words.size(); i++)
      {
        if (isPalindrome(words[i]))
        {
          return words[i];
        }
      }
      return "";
    }
  }
};

int main()
{
  Solution s;
  vector<string> words = {"abc", "car", "ada", "racecar", "cool"};
  cout << s.firstPalindrome(words) << endl;
  return 0;
}