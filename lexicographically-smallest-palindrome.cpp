#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string makeSmallestPalindrome(string s)
  {
    // convert string to char array
    char arr[s.length() + 1];
    strcpy(arr, s.c_str());

    int i = 0, j = s.length() - 1;
    while (i < j)
    {
      if (arr[i] != arr[j])
      {
        char min = arr[i] < arr[j] ? arr[i] : arr[j];
        arr[i] = min;
        arr[j] = min;
      }
      i++;
      j--;
    }
    // convert arrays to string
    string str(arr);
    return str;
  }
};

int main()
{
  Solution s;
  string str = "BAAABAB";
  cout << s.makeSmallestPalindrome(str) << endl;
  return 0;
}