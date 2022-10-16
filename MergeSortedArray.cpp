#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
      if (nums1[i] > nums2[j])
        nums1[k--] = nums1[i--];
      else
        nums1[k--] = nums2[j--];
    }
    while (j >= 0)
      nums1[k--] = nums2[j--];

    // print the merged array
    for (int i = 0; i < m + n; i++)
      cout << nums1[i] << " ";
  }
};

int main()
{
  Solution s;
  int m = 3, n = 3;
  vector<int> nums1 = {1, 2, 3, 0, 0, 0}, nums2 = {2, 5, 6};
  s.merge(nums1, m, nums2, n);
  return 0;
}