#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
  {
    vector<int> res;
    sort(potions.begin(), potions.end());
    int n = spells.size();
    int m = potions.size();

    for (int i = 0; i < n; i++)
    {
      int low = 0, high = m - 1;
      while (low <= high)
      {
        int mid = (low + high) / 2;
        long n1 = potions[mid];
        long n2 = spells[i];
        if (n1 * n2 < success)
        {
          low = mid + 1;
        }
        else
        {
          high = mid - 1;
        }
      }
      res.emplace_back(m - low);
    }
    return res;
  }
};

int main()
{

  vector<int> spells = {1, 2, 3, 4, 5};
  vector<int> potions = {1, 2, 3, 4, 5};
  long long success = 10;
  Solution obj;
  vector<int> res = obj.successfulPairs(spells, potions, success);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
