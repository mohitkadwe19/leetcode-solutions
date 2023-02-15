#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> addToArrayForm(vector<int> &num, int k)
  {
    vector<int> ans;
    int carry = 0;
    int i = num.size() - 1;
    while (i >= 0 || k > 0 || carry > 0)
    {
      int sum = carry;
      if (i >= 0)
      {
        sum += num[i];
        i--;
      }
      if (k > 0)
      {
        sum += k % 10;
        k /= 10;
      }
      ans.push_back(sum % 10);
      carry = sum / 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> num = {1, 2, 0, 0};
  int k = 34;
  vector<int> ans = s.addToArrayForm(num, k);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}