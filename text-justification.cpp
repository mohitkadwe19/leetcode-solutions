#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth)
  {

    int n = words.size();
    int i = 0;

    vector<string> result;
    while (i < n)
    {
      int j = i;
      int lineLength = 0;

      while (j < n && lineLength + words[j].size() + (j - i) <= maxWidth)
      {
        lineLength += words[j].size();
        j++;
      }

      int wordCount = j - i;
      int spaceCount = maxWidth - lineLength;

      if (wordCount == 1 || j == n)
      {
        string line = words[i];
        for (int k = i + 1; k < j; k++)
        {
          line += " " + words[k];
        }
        line += string(maxWidth - line.size(), ' ');
        result.push_back(line);
      }
      else
      {
        int avgSpaces = spaceCount / (wordCount - 1);
        int extraSpaces = spaceCount % (wordCount - 1);

        string line = words[i];
        for (int k = i + 1; k < j; k++)
        {
          int spaces;
          if (extraSpaces > 0)
          {
            spaces = avgSpaces + 1;
            extraSpaces--;
          }
          else
            spaces = avgSpaces;
          line += string(spaces, ' ') + words[k];
        }
        result.push_back(line);
      }

      i = j;
    }
    return result;
  }
};

int main()
{
  Solution sol;
  vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
  vector<string> result = sol.fullJustify(words, 16);
  for (auto &w : result)
  {
    cout << w << endl;
  }
  return 0;
}