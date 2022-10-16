#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  void deleteNode(ListNode *node)
  {
    ListNode *temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    delete temp;
  }
};

int main()
{
  Solution sol;
  ListNode *head = new ListNode(4);
  head->next = new ListNode(5);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(9);
  sol.deleteNode(head->next);
  for (ListNode *p = head; p != NULL; p = p->next)
    cout << p->val << " ";
  return 0;
}