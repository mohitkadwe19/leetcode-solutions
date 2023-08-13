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
  ListNode *reverseListNode(ListNode *head)
  {
    ListNode *prev = nullptr;
    ListNode *current = head;
    while (current != nullptr)
    {
      ListNode *nextNode = current->next;
      current->next = prev;
      prev = current;
      current = nextNode;
    }
    return prev;
  }
  ListNode *doubleIt(ListNode *head)
  {
    if (!head)
      return head;

    head = reverseListNode(head);

    ListNode *current = head;
    ListNode *newHead = nullptr;
    int carry = 0;

    while (current != nullptr)
    {
      int newVal = current->val * 2 + carry;
      carry = newVal / 10;
      newVal %= 10;

      if (newHead == nullptr)
      {
        newHead = new ListNode(newVal);
      }
      else
      {
        ListNode *newNode = new ListNode(newVal);
        newNode->next = newHead;
        newHead = newNode;
      }

      current = current->next;
    }

    if (carry > 0)
    {
      ListNode *newNode = new ListNode(carry);
      newNode->next = newHead;
      newHead = newNode;
    }

    return newHead;
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

  ListNode *ans = sol.doubleIt(head);
  while (ans)
  {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
  return 0;
}