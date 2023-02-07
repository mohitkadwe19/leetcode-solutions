#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int totalFruit(vector<int> &fruits)
  {
    int n = fruits.size();
    int i = 0, j = 0, ans = 0;
    unordered_map<int, int> mp;
    while (j < n)
    {
      mp[fruits[j]]++;
      while (mp.size() > 2)
      {
        mp[fruits[i]]--;
        if (mp[fruits[i]] == 0)
          mp.erase(fruits[i]);
        i++;
      }
      ans = max(ans, j - i + 1);
      j++;
    }
    return ans;
  }
};

int main()
{
  vector<int> fruits = {1, 2, 1};
  Solution obj;
  cout << obj.totalFruit(fruits) << endl;
  return 0;
}