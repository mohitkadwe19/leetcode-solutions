#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int snakesAndLadders(vector<vector<int>> &board)
  {
    int n = board.size();
    int steps = 0;
    queue<int> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    q.push(1);
    visited[n - 1][0] = true;
    while (!q.empty())
    {
      int sz = q.size();
      for (int i = 0; i < sz; i++)
      {
        int f = q.front();
        q.pop();
        if (f == n * n)
        {
          return steps;
        }
        for (int k = 1; k <= 6; k++)
        {
          int curr = k + f;
          if (curr > n * n)
          {
            break;
          }
          int r = n - (curr - 1) / n - 1;
          int c = (r % 2 == n % 2) ? n - 1 - (curr - 1) % n : (curr - 1) % n;
          if (visited[r][c])
          {
            continue;
          }
          visited[r][c] = true;
          if (board[r][c] == -1)
          {
            q.push(curr);
          }
          else
          {
            q.push(board[r][c]);
          }
        }
      }
      steps++;
    }
    return -1;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> board = {{-1, -1, -1, -1, -1, -1},
                               {-1, -1, -1, -1, -1, -1},
                               {-1, -1, -1, -1, -1, -1},
                               {-1, 35, -1, -1, 13, -1},
                               {-1, -1, -1, -1, -1, -1},
                               {-1, 15, -1, -1, -1, -1}};
  cout << s.snakesAndLadders(board) << endl;
  return 0;
}