#include <bits/stdc++.h>
using namespace std;

int countBlackBox(string str)
{
  int count = 0;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == 'B')
      count++;
  }
  return count;
}

class Solution
{
public:
  int minimumRecolors(string blocks, int k)
  {
    int min_counter = INT_MAX;
    int n = blocks.length();
    for (int i = 0; i < n; i++)
    {
      string sub_str = blocks.substr(i, k);
      int no_of_black_boxes = countBlackBox(sub_str);
      int remaining;
      if (k > no_of_black_boxes)
      {
        remaining = k - no_of_black_boxes;
      }
      else
      {
        remaining = 0;
      }
      if (remaining < min_counter)
      {
        min_counter = remaining;
      }
    }
    return min_counter;
  }
};

int main()
{
  Solution sol;
  string blocks = "WBBWWBBWBW";
  int k = 7;
  cout << sol.minimumRecolors(blocks, k) << endl;
}