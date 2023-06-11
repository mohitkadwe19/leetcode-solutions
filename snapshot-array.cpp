#include <bits/stdc++.h>
using namespace std;

class SnapshotArray
{
  int snapi = 0;
  vector<map<int, int>> a;

public:
  SnapshotArray(int length)
  {
    a.resize(length);
    for (auto &i : a)
      i[0] = 0;
    snapi = 0;
  }

  void set(int index, int val)
  {
    a[index][snapi] = val;
  }

  int snap()
  {
    return snapi++;
  }

  int get(int index, int snap_id)
  {
    return ((--a[index].upper_bound(snap_id))->second);
  }
};

int main()
{
  int length = 3;
  SnapshotArray *obj = new SnapshotArray(length);
  obj->set(0, 5);
  int param_2 = obj->snap();
  int param_3 = obj->get(0, 0);
  return 0;
}