#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet
{
public:
  int mini;
  unordered_map<int, bool> mp;
  SmallestInfiniteSet()
  {
    mini = 1;
  }

  int popSmallest()
  {
    int i = 0;
    while (mp[mini + i])
    {
      i++;
    }
    mp[mini + i] = true;
    mini += i + 1;
    return mini - 1;
  }

  void addBack(int num)
  {
    if (mp[num])
    {
      mini = min(mini, num);
      mp[num] = false;
    }
  }
};

int main()
{
  int num = 0;
  SmallestInfiniteSet *obj = new SmallestInfiniteSet();
  int param_1 = obj->popSmallest();
  obj->addBack(num);
}