#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canMakeArithmeticProgression(vector<int> &arr)
  {
    sort(arr.begin(), arr.end());
    int diff = arr[1] - arr[0];
    for (int i = 2; i < arr.size(); i++)
    {
      if (arr[i] - arr[i - 1] != diff)
        return false;
    }
    return true;
  }
};

int main()
{
  Solution s;
  vector<int> arr = {3, 5, 1};
  cout << s.canMakeArithmeticProgression(arr) << endl;
  return 0;
}