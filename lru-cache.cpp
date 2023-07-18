#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
  list<pair<int, int>> l;
  unordered_map<int, list<pair<int, int>>::iterator> mp;
  int size = 0;
  LRUCache(int capacity)
  {
    size = capacity;
    mp.clear();
    l.clear();
  }

  int get(int key)
  {
    if (mp.find(key) != mp.end())
    {
      // reorder element
      int value = mp[key]->second;
      l.erase(mp[key]);
      l.push_front({key, value});
      mp[key] = l.begin();

      return mp[key]->second;
    }
    return -1;
  }

  void put(int key, int value)
  {
    if (mp.find(key) != mp.end())
    {
      // erase old sequence of key
      l.erase(mp[key]);
    }
    if (l.size() == size)
    {
      // remove least recently used key
      list<pair<int, int>>::iterator it = l.end();
      it--;
      mp.erase(mp.find(it->first));
      l.pop_back();
    }
    // insert in the front of queue
    l.push_front({key, value});
    mp[key] = l.begin();
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
  LRUCache *obj = new LRUCache(3);
  obj->put(1, 1);
  obj->put(2, 2);
  obj->put(3, 3);
  obj->put(4, 4);
  cout << obj->get(4) << endl;
  return 0;
}