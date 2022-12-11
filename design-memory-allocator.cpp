#include <bits/stdc++.h>
using namespace std;

class Allocator
{
public:
  int n = 0;
  vector<int> arr;
  unordered_map<int, int> mp;

  Allocator(int n)
  {
    this->n = n;
    arr.resize(n);
  }

  int allocate(int size, int mID)
  {
    for (int i = 0; i < n; i++)
    {
      if (arr[i] == 0)
      {
        int a = i, b = 0;

        while (i < n and arr[i] == 0)
        {
          i++, b++;
          if (b == size)
          {
            break;
          }
        }
        if (b >= size)
        {
          for (int j = a; j < a + size; j++)
          {
            arr[j] = mID;
          }

          mp[mID] = a;

          return a;
        }
      }
    }

    return -1;
  }

  int free(int mID)
  {
    int i = mp[mID], b = 0;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] == mID)
        b++, arr[i] = 0;
    }
    mp.erase(mID);
    return b;
  }
};

int main()
{
}