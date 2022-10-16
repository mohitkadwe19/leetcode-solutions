#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int lengthOfLastWord(string s)
  {
    // store the last word in a string
    string lastWord;
    // store the length of the last word
    int lastWordLength = 0;

    for (int i = s.length() - 1; i >= 0; i--)
    {
      // check the character is a space character or not
      if (s[i] == ' ' && lastWord.length() == 0)
      {
        continue;
      }
      if (s[i] == ' ' && lastWord.length() != 0)
      {
        break;
      }
      else if (s[i] != ' ')
      {
        lastWord += s[i];
      }
    }

    return lastWord.length();
  }
};

int main()
{
  Solution S;
  string s = "luffy is still joyboy";
  cout << S.lengthOfLastWord(s) << endl;
  return 0;
}