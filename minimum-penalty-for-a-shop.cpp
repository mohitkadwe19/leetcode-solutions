#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int bestClosingTime(string customers)
  {
    int temp = 0, min = customers.length(), index = 0;

    for (int i = 0; i < customers.length(); i++)
      if (customers[i] == 'Y')
        temp++;

    if (!temp)
      return 0;
    if (temp < min)
    {
      min = temp;
      index = 0;
    }

    for (int i = 0; i < customers.length(); i++)
    {

      if (customers[i] == 'N')
        temp++;
      else
        temp--;

      if (!temp)
        return i + 1;
      if (temp < min)
      {
        min = temp;
        index = i + 1;
      }
    }
    return index;
  }
};

int main()
{
  Solution sol;
  cout << sol.bestClosingTime("YYN") << endl;
  return 0;
}