#include <bits/stdc++.h>
using namespace std;

class LFUCache
{
public:
  int maxSizeCache;                                // maximum capacity of the cache
  int size;                                        // current number of elements in the cache
  int minFreq;                                     // the minimum frequency of elements in the cache
  unordered_map<int, pair<int, int>> keyNode;      // key to {value,freq}
  unordered_map<int, list<int>::iterator> keylist; // key to list iterator
  unordered_map<int, list<int>> freqKeyLt;         // freq to key list
public:
  LFUCache(int capacity)
  {
    maxSizeCache = capacity; // setting the maximum capacity of the cache
    size = 0;                // initially the size is zero
  }

  int get(int key)
  {
    // if the key is not in the cache, return -1
    if (keyNode.count(key) == 0)
      return -1;

    // remove the key from its current frequency list
    freqKeyLt[keyNode[key].second].erase(keylist[key]);

    // increase the frequency of the key
    keyNode[key].second++;

    // add the key to the frequency list with its new frequency
    freqKeyLt[keyNode[key].second].push_back(key);

    // update the key's position in the keylist
    keylist[key] = --freqKeyLt[keyNode[key].second].end();

    // if the list of minimum frequency is empty, update the minimum frequency
    if (freqKeyLt[minFreq].size() == 0)
      minFreq++;

    // return the value associated with the key
    return keyNode[key].first;
  }

  void put(int key, int value)
  {
    // if the cache has a maximum capacity of 0, return
    if (maxSizeCache <= 0)
      return;

    // check if the key already exists in the cache
    int storedValue = get(key);
    if (storedValue != -1)
    {
      // if the key already exists, update its value
      keyNode[key].first = value;
      return;
    }

    // if the cache is full, remove the least frequently used key
    if (size >= maxSizeCache)
    {
      keyNode.erase(freqKeyLt[minFreq].front());
      keylist.erase(freqKeyLt[minFreq].front());
      freqKeyLt[minFreq].pop_front();
      size--;
    }

    // add the new key to the cache
    keyNode[key] = {value, 1};
    freqKeyLt[1].push_back(key);
    keylist[key] = --freqKeyLt[1].end();
    minFreq = 1;
    size++;
  }
  int maxSizeCache;                                // maximum capacity of the cache
  int size;                                        // current number of elements in the cache
  int minFreq;                                     // the minimum frequency of elements in the cache
  unordered_map<int, pair<int, int>> keyNode;      // key to {value,freq}
  unordered_map<int, list<int>::iterator> keylist; // key to list iterator
  unordered_map<int, list<int>> freqKeyLt;         // freq to key list
public:
  LFUCache(int capacity)
  {
    maxSizeCache = capacity; // setting the maximum capacity of the cache
    size = 0;                // initially the size is zero
  }

  int get(int key)
  {
    // if the key is not in the cache, return -1
    if (keyNode.count(key) == 0)
      return -1;

    // remove the key from its current frequency list
    freqKeyLt[keyNode[key].second].erase(keylist[key]);

    // increase the frequency of the key
    keyNode[key].second++;

    // add the key to the frequency list with its new frequency
    freqKeyLt[keyNode[key].second].push_back(key);

    // update the key's position in the keylist
    keylist[key] = --freqKeyLt[keyNode[key].second].end();

    // if the list of minimum frequency is empty, update the minimum frequency
    if (freqKeyLt[minFreq].size() == 0)
      minFreq++;

    // return the value associated with the key
    return keyNode[key].first;
  }

  void put(int key, int value)
  {
    // if the cache has a maximum capacity of 0, return
    if (maxSizeCache <= 0)
      return;

    // check if the key already exists in the cache
    int storedValue = get(key);
    if (storedValue != -1)
    {
      // if the key already exists, update its value
      keyNode[key].first = value;
      return;
    }

    // if the cache is full, remove the least frequently used key
    if (size >= maxSizeCache)
    {
      keyNode.erase(freqKeyLt[minFreq].front());
      keylist.erase(freqKeyLt[minFreq].front());
      freqKeyLt[minFreq].pop_front();
      size--;
    }

    // add the new key to the cache
    keyNode[key] = {value, 1};
    freqKeyLt[1].push_back(key);
    keylist[key] = --freqKeyLt[1].end();
    minFreq = 1;
    size++;
  }
};

int main()
{
  LFUCache *cache = new LFUCache(2);
  cache->put(1, 1);
  cache->put(2, 2);
  cout << cache->get(1) << endl; // returns 1

  return 0;
}