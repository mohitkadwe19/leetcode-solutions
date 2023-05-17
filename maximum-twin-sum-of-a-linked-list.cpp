#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  int pairSum(ListNode *head)
  {
    ListNode *temp = head;
    stack<int> s;
    while (temp)
    {
      s.push(temp->val);
      temp = temp->next;
    }
    int mx = 0;
    while (s.size())
    {
      mx = max(mx, s.top() + head->val);
      head = head->next;
      s.pop();
    }
    return mx;
  }
};

int main()
{
  Solution s;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(4);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(2);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(2);

  cout << s.pairSum(head) << endl;
  return 0;
}