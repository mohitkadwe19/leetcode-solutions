#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
  {
    int n = words.size(), i = 0;
    vector<int> vec(n), previousArray(n);

    for (auto x : words)
    {
      int l = x.size() - 1;
      if ((x[0] == 'a' or x[0] == 'e' or x[0] == 'i' or x[0] == 'o' or x[0] == 'u') and (x[l] == 'a' or x[l] == 'e' or x[l] == 'i' or x[l] == 'o' or x[l] == 'u'))
      {
        vec[i++] = 1;
      }
      else
      {
        vec[i++] = 0;
      }
    }

    previousArray[0] = vec[0];

    for (int i = 1; i < n; i++)
    {
      previousArray[i] = previousArray[i - 1] + vec[i];
    }

    int q = queries.size();
    vector<int> ans(q, 0);

    for (int i = 0; i < q; i++)
    {
      int st = queries[i][0];
      int end = queries[i][1];

      if (st == 0)
      {
        ans[i] = previousArray[end];
      }
      else
      {
        ans[i] = previousArray[end] - previousArray[st - 1];
      }
    }
    return ans;
  }
};

int main()
{
  vector<string> words = {"abc", "aabc", "bc"};
  vector<vector<int>> queries = {{3, 3}, {1, 2}, {0, 2}};
  Solution s;
  vector<int> ans = s.vowelStrings(words, queries);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}