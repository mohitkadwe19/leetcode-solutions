#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool dfs(vector<int> *list, vector<int> &visited, int source)
  {
    if (visited[source])
    {
      return false;
    }
    visited[source] = true;
    for (auto child : list[source])
    {
      if (visited[child] != 2)
      {

        if (dfs(list, visited, child) == false)
        {
          return false;
        }
      }
    }
    visited[source] = 2;
    return true;
  }
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    int n = numCourses;
    vector<int> list[n];
    for (int i = 0; i < prerequisites.size(); i++)
    {
      list[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    vector<int> visited(n + 1, false);
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        if (dfs(list, visited, i) == false)
        {
          return false;
        }
      }
    }
    return true;
  }
};

int main()
{
  Solution sol;
  int numCourses = 2;
  vector<vector<int>> prerequisites = {{1, 0}};
  cout << sol.canFinish(numCourses, prerequisites) << endl;
  return 0;
}