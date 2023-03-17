#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
  unordered_map<string, int> mpp, mp;
  Trie()
  {
  }
  void insert(string word)
  {
    mpp[word]++;
    string s;
    for (auto it : word)
    {
      s.push_back(it);
      if (mp[s] == 0)
      {
        mp[s]++;
      }
    }
  }

  bool search(string word)
  {
    if (mpp[word])
    {
      return true;
    }
    return false;
  }

  bool startsWith(string prefix)
  {
    if (mp[prefix])
    {
      return true;
    }
    return false;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
  Trie *obj = new Trie();
  obj->insert("apple");
  cout << obj->search("apple") << endl;   // 1
  cout << obj->search("app") << endl;     // 0
  cout << obj->startsWith("app") << endl; // 1
  obj->insert("app");
  cout << obj->search("app") << endl; // 1
  return 0;
}