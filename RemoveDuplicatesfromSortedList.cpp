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
  ListNode *deleteDuplicates(ListNode *head)
  {

    if (head == NULL)
      return NULL;
    ListNode *p = head;
    while (p->next != NULL)
    {
      if (p->val == p->next->val)
      {
        p->next = p->next->next;
      }
      else
      {
        p = p->next;
      }
    }
    return head;
  }
};

int main()
{
  Solution s;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(1);
  head->next->next = new ListNode(2);
  ListNode *res = s.deleteDuplicates(head);
  while (res)
  {
    cout << res->val << " ";
    res = res->next;
  }
  return 0;
}