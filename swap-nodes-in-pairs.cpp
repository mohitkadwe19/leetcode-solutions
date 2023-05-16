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
  ListNode *swapPairs(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *temp = head->next;
    head->next = swapPairs(temp->next);
    temp->next = head;
    return temp;
  }
};

int main()
{
  ListNode *head = new ListNode(1);
  ListNode *temp = head;
  for (int i = 2; i <= 4; i++)
  {
    temp->next = new ListNode(i);
    temp = temp->next;
  }
  Solution sol;
  ListNode *ans = sol.swapPairs(head);
  while (ans != nullptr)
  {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
  return 0;
}