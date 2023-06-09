#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  char nextGreatestLetter(vector<char> &letters, char target)
  {
    int n = letters.size();
    int start = 0, end = n - 1;
    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (letters[mid] <= target)
        start = mid + 1;
      else
        end = mid - 1;
    }
    return letters[start % n];
  }
};

int main()
{
  Solution s;
  vector<char> letters = {'c', 'f', 'j'};
  char target = 'a';
  cout << s.nextGreatestLetter(letters, target) << endl;
  return 0;
}