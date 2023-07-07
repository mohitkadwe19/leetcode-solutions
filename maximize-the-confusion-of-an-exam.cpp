#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxConsecutiveAnswers(string answerKey, int k)
  {
    int n = answerKey.size();
    int left = 0, right = 0, maxLen = 0, maxFreq = 0;
    unordered_map<char, int> freq;
    while (right < n)
    {
      freq[answerKey[right]]++;
      maxFreq = max(maxFreq, freq[answerKey[right]]);
      if (right - left + 1 - maxFreq > k)
      {
        freq[answerKey[left]]--;
        left++;
      }
      maxLen = max(maxLen, right - left + 1);
      right++;
    }
    return maxLen;
  }
};

int main()
{
  string answerKey = "TTFF";
  int k = 2;
  Solution sol;
  cout << sol.maxConsecutiveAnswers(answerKey, k) << endl;
  return 0;
}