#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0),
               next(nullptr) {}
  ListNode(int x) : val(x),
                    next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x),
                                    next(next) {}
};

class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
      count++;
      temp = temp->next;
    }
    if (count == n)
    {
      head = head->next;
      return head;
    }
    temp = head;
    for (int i = 0; i < count - n - 1; i++)
    {
      temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
  }
};

int main()
{
  Solution *s = new Solution();
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  ListNode *ans = s->removeNthFromEnd(head, 2);
  while (ans != NULL)
  {
    cout << ans->val << " ";
    ans = ans->next;
  }
}