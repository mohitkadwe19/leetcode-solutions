#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
  {
    int n = req_skills.size();
    int m = people.size();

    unordered_map<string, int> skillMap; // Map skill to index
    for (int i = 0; i < n; i++)
    {
      skillMap[req_skills[i]] = i;
    }

    vector<int> dp((1 << n), INT_MAX); // dp bitmask to store minimum team size for each skill combination
    dp[0] = 0;                         // Base case: empty skill set

    vector<vector<int>> team((1 << n)); // team[i] stores the people indices for skill combination i
    for (int i = 0; i < m; i++)
    {
      int personSkills = 0; // bitmask to represent skills of a person
      for (string skill : people[i])
      {
        personSkills |= (1 << skillMap[skill]); // set the corresponding skill bit
      }

      for (int j = 0; j < (1 << n); j++)
      {
        if (dp[j] == INT_MAX)
          continue;

        int nextSkills = j | personSkills; // combine current skill set with person's skills

        if (dp[j] + 1 < dp[nextSkills])
        {
          dp[nextSkills] = dp[j] + 1;
          team[nextSkills] = team[j]; // Copy previous team

          team[nextSkills].push_back(i); // Add current person to the team
        }
      }
    }

    return team[(1 << n) - 1]; // Return the team for full skill set
  }
};

int main()
{
  vector<string> req_skills = {"A", "B", "C"};
  vector<vector<string>> people = {
      {"A", "B"},
      {"A", "C"},
      {"B", "C"}};
  Solution obj;
  vector<int> people = obj.smallestSufficientTeam(req_skills, people);
  for (int i = 0; i < people.size(); i++)
  {
    cout << people[i] << " ";
  }
  return 0;
}