#include <bits/stdc++.h>
using namespace std;

class MyCalendarThree
{
public:
  map<int, int> mp;
  int max_count = 0;
  MyCalendarThree()
  {
  }

  int book(int start, int end)
  {
    mp[start]++;
    mp[end]--;
    int count = 0;
    for (auto it : mp)
    {
      count += it.second;
      max_count = max(max_count, count);
    }
    return max_count;
  }
};

int main()
{
  MyCalendarThree *obj = new MyCalendarThree();
  cout << obj->book(10, 20) << endl;
  cout << obj->book(50, 60) << endl;
  cout << obj->book(10, 40) << endl;
  return 0;
}