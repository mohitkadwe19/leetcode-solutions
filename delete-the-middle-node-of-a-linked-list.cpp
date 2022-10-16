#include <bits/stdc++.h>
using namespace std;

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
  ListNode *deleteMiddle(ListNode *head)
  {
    if (head == NULL || head->next == NULL)
    {
      return NULL;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;
    while (fast != nullptr && fast->next != nullptr)
    {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = slow->next;
    return head;
  }
};

int main()
{
  Solution sol;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(8);
  head->next->next->next->next->next->next->next->next = new ListNode(9);
  head->next->next->next->next->next->next->next->next->next = new ListNode(10);
  ListNode *res = sol.deleteMiddle(head);
  while (res != NULL)
  {
    cout << res->val << " ";
    res = res->next;
  }
  return 0;
}