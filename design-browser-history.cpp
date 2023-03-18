#include <bits/stdc++.h>
using namespace std;

class BrowserHistory
{
public:
  BrowserHistory(string homepage)
  {
    history.push_back(homepage);
    cur_idx = 0;
  }

  void visit(string url)
  {
    // Clear forward history
    history.resize(cur_idx + 1);
    history.push_back(url);
    cur_idx++;
  }

  string back(int steps)
  {
    int prev_idx = max(0, cur_idx - steps);
    cur_idx = prev_idx;
    return history[cur_idx];
  }

  string forward(int steps)
  {
    int next_idx = min((int)history.size() - 1, cur_idx + steps);
    cur_idx = next_idx;
    return history[cur_idx];
  }

private:
  vector<string> history;
  int cur_idx;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main()
{
  BrowserHistory *obj = new BrowserHistory("leetcode.com");
  obj->visit("google.com");        // You are in "leetcode.com". Visit "google.com"
  obj->visit("facebook.com");      // You are in "google.com". Visit "facebook.com"
  obj->visit("youtube.com");       // You are in "facebook.com". Visit "youtube.com"
  cout << obj->back(1) << endl;    // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
  cout << obj->back(1) << endl;    // You are in "facebook.com", move back to "google.com" return "google.com"
  cout << obj->forward(1) << endl; // You are in "google.com", move forward to "facebook.com" return "facebook.com"
  obj->visit("linkedin.com");      // You are in "facebook.com". Visit "linkedin.com"

  cout << obj->forward(2) << endl; // You are in "linkedin.com", you cannot move forward any steps.

  return 0;
}