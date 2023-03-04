#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int splitNum(int num)
  {

    string str = to_string(num), a = "", b = "";
    sort(str.begin(), str.end());

    for (int i = 0; i < str.length(); i += 2)
    {
      a += str[i];
    }
    for (int i = 1; i < str.length(); i += 2)
    {
      b += str[i];
    }

    int A = stoi(a);
    int B = stoi(b);

    return A + B;
  }
};

int main()
{
  int num;
  cin >> num;
  Solution obj;
  cout << obj.splitNum(num) << endl;
  return 0;
}