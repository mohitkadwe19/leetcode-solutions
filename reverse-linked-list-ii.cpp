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
  ListNode *reverseBetween(ListNode *head, int left, int right)
  {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy;
    for (int i = 0; i < left - 1; i++)
    {
      pre = pre->next;
    }
    ListNode *cur = pre->next;
    ListNode *next = cur->next;
    for (int i = 0; i < right - left; i++)
    {
      cur->next = next->next;
      next->next = pre->next;
      pre->next = next;
      next = cur->next;
    }
    return dummy->next;
  }
};

int main()
{
  Solution s;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  int left = 2;
  int right = 4;
  ListNode *ans = s.reverseBetween(head, left, right);
  while (ans != nullptr)
  {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
  return 0;
}