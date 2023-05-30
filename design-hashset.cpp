#include <bits/stdc++.h>
using namespace std;

class MyHashSet
{
public:
  vector<int> s;
  MyHashSet()
  {
    s.resize(1e6 + 1, 0);
  }

  void add(int key)
  {
    s[key] = 1;
  }

  void remove(int key)
  {
    s[key] = 0;
  }

  bool contains(int key)
  {
    return s[key];
  }
};

int main()
{
  MyHashSet *obj = new MyHashSet();
  obj->add(1);
  obj->remove(2);
  bool param_3 = obj->contains(3);
  cout << param_3 << endl;
  return 0;
}