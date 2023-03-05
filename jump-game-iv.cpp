#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minJumps(vector<int> &arr)
  {
    int n = arr.size();
    if (n == 1)
      return 0;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
      mp[arr[i]].push_back(i);
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    int ans = 0;
    while (!q.empty())
    {
      int sz = q.size();
      while (sz--)
      {
        int cur = q.front();
        q.pop();
        if (cur == n - 1)
          return ans;
        if (cur - 1 >= 0 && !vis[cur - 1])
        {
          q.push(cur - 1);
          vis[cur - 1] = true;
        }
        if (cur + 1 < n && !vis[cur + 1])
        {
          q.push(cur + 1);
          vis[cur + 1] = true;
        }
        for (int i : mp[arr[cur]])
        {
          if (!vis[i])
          {
            q.push(i);
            vis[i] = true;
          }
        }
        mp[arr[cur]].clear();
      }
      ans++;
    }
    return -1;
  }
};

int main()
{
  Solution s;
  vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
  cout << s.minJumps(arr) << endl;
  return 0;
}