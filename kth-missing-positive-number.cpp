#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findKthPositive(vector<int> &arr, int k)
  {
    int n = arr.size();
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < n)
    {
      if (arr[i] == j + 1)
      {
        i++;
        j++;
      }
      else
      {
        count++;
        j++;
        if (count == k)
        {
          return j;
        }
      }
    }
    return j + k - count;
  }
};

int main()
{
  int k = 5;
  vector<int> arr = {2, 3, 4, 7, 11};
  Solution obj;
  cout << obj.findKthPositive(arr, k) << endl;
  return 0;
}