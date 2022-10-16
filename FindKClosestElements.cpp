#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x)
  {
    // int n = arr.size();
    // int l = 0, r = n - k;
    // while (l < r)
    // {
    //   int mid = l + (r - l) / 2;
    //   if (x - arr[mid] > arr[mid + k] - x)
    //     l = mid + 1;
    //   else
    //     r = mid;
    // }
    // return vector<int>(arr.begin() + l, arr.begin() + l + k);
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < arr.size(); i++)
    {
      pq.push({abs(arr[i] - x), arr[i]});
      if (pq.size() > k)
        pq.pop();
    }
    vector<int> ans;
    while (!pq.empty())
    {
      ans.push_back(pq.top().second);
      pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> arr = {1, 2, 3, 4, 5};
  int k = 4, x = 3;
  vector<int> ans = s.findClosestElements(arr, k, x);
  for (int i : ans)
    cout << i << " ";
  return 0;
}