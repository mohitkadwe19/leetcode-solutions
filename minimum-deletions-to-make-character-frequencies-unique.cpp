#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minDeletions(string s)
  {
    int deletionsCount = 0;                // Initialize a variable to keep track of deletions.
    unordered_map<int, bool> frequencyMap; // Create a map to track seen frequencies.
    vector<int> charFrequencyCount(26, 0); // Create a vector to count character frequencies (assuming lowercase English letters).
    int n = s.size();                      // Get the length of the input string.

    // Iterate through the characters in the input string to count their frequencies.
    for (int i = 0; i < n; i++)
      charFrequencyCount[s[i] - 'a']++;

    // Iterate through the possible frequencies (assuming lowercase English letters).
    for (int i = 0; i < 26; i++)
    {
      int frequency = charFrequencyCount[i];

      // If this frequency has been seen before in the map, make it unique.
      if (frequencyMap[frequency] == true)
      {
        while (frequencyMap[frequency] == true && frequency > 0)
        {
          frequency--;
          deletionsCount++;
        }
        if (frequency > 0)
          frequencyMap[frequency] = true;
      }
      else
        frequencyMap[frequency] = true;
    }

    // Return the total number of deletions needed to make frequencies unique.
    return deletionsCount;
  }
};

int main()
{
  Solution s;
  cout << s.minDeletions("ceabaacb") << endl;
  return 0;
}