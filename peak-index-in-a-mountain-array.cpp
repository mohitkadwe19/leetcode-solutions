#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int peakIndexInMountainArray(vector<int> &arr)
  {
    int n = arr.size();
    int l = 0, r = n - 1;
    while (l < r)
    {
      int mid = l + (r - l) / 2;
      if (arr[mid] > arr[mid + 1])
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }
};

int main()
{
  vector<int> arr = {1, 2, 3, 1};
  Solution s;
  int ans = s.peakIndexInMountainArray(arr);
  return 0;
}