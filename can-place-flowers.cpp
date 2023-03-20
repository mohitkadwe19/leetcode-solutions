#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canPlaceFlowers(vector<int> &fd, int n)
  {
    int pre = 1;
    for (int i = 0; i < fd.size(); i++)
    {
      if (pre == 1 && fd[i] == 0)
      {
        if (i + 1 < fd.size() && fd[i + 1] == 0)
        {
          pre = 0;
          n--;
        }
        else if (i + 1 == fd.size())
        {
          pre = 0;
          n--;
        }
      }
      else if (fd[i] == 0)
        pre = 1;
      else
        pre = 0;
    }
    return n <= 0;
  }
};

int main()
{
  Solution s;
  vector<int> flowerbed = {1, 0, 0, 0, 1};
  int n = 1;
  cout << s.canPlaceFlowers(flowerbed, n) << endl;
  return 0;
}