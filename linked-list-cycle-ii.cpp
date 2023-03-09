#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *detectCycle(ListNode *head)
  {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
      {
        slow = head;
        while (slow != fast)
        {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }
    return NULL;
  }
};

int main()
{
  ListNode *Node;
  Node = new ListNode(3);
  Node->next = new ListNode(2);
  Node->next->next = new ListNode(0);
  Node->next->next->next = new ListNode(-4);
  Node->next->next->next->next = Node->next;

  Solution *sol = new Solution();
  cout << sol->detectCycle(Node)->val << endl;
  return 0;
}