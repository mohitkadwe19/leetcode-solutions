#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maxDiamonds(int A[], int N, int K)
  {
    priority_queue<int> pq;
    for (int i = 0; i < N; i++)
    {
      pq.push(A[i]);
    }

    long long ans = 0;

    for (int i = 0; i < K; i++)
    {
      long long temp = pq.top();
      ans += temp;
      pq.pop();
      pq.push(temp / 2);
    }
    return ans;
    }
};

int main()
{
  int N = 5, K = 3;
  int A[] = {2, 1, 7, 4, 2};
  Solution ob;
  cout << ob.maxDiamonds(A, N, K) << endl;
  return 0;
}