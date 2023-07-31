#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumDeleteSum(string s1, string s2)
  {
    unordered_map<char, int> m;
    long tsum = 0;
    for (auto c : s1)
    {
      tsum += c;
    }
    for (auto c : s2)
    {
      tsum += c;
    }

    long n1 = s1.length(), n2 = s2.length();
    vector<vector<int>> sum(n1 + 1, vector<int>(n2 + 1, 0));
    int max_sum = 0;
    for (int i = 1; i <= n1; i++)
    {
      for (int j = 1; j <= n2; j++)
      {
        if (s1[i - 1] == s2[j - 1])
        {
          sum[i][j] = sum[i - 1][j - 1] + s1[i - 1];
          // cout<<(int)s1[i-1]<<endl;
        }
        else
        {
          sum[i][j] = max(sum[i][j - 1], sum[i - 1][j]);
        }

        max_sum = max(max_sum, sum[i][j]);
      }
    }

    return tsum - 2 * max_sum;
  }
};

int main()
{
  string s1 = "sea", s2 = "eat";
  Solution s;
  cout << s.minimumDeleteSum(s1, s2);
  return 0;
}