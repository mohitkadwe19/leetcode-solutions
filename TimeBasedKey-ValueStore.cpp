#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
public:
  unordered_map<string, map<int, string>> m;
  TimeMap()
  {
    m.clear();
  }

  void set(string key, string value, int timestamp)
  {
    m[key][timestamp] = value;
  }

  string get(string key, int timestamp)
  {
    if (m.find(key) == m.end())
      return "";
    auto it = m[key].upper_bound(timestamp);
    if (it == m[key].begin())
      return "";
    return prev(it)->second;
  }
};

int main()
{
  TimeMap *obj = new TimeMap();
  obj->set("foo", "bar", 1);
  cout << obj->get("foo", 1) << endl;
  cout << obj->get("foo", 3) << endl;
  obj->set("foo", "bar2", 4);
  cout << obj->get("foo", 4) << endl;
  cout << obj->get("foo", 5) << endl;
  return 0;
}