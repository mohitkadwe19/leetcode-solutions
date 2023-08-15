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
  ListNode *partition(ListNode *head, int x)
  {
    ListNode *small = new ListNode(0);
    ListNode *big = new ListNode(0);
    ListNode *smallHead = small;
    ListNode *bigHead = big;
    while (head)
    {
      if (head->val < x)
      {
        small->next = head;
        small = small->next;
      }
      else
      {
        big->next = head;
        big = big->next;
      }
      head = head->next;
    }
    small->next = bigHead->next;
    big->next = nullptr;
    return smallHead->next;
  }
};

int main()
{
  Solution s;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(4);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(2);

  ListNode *ans = s.partition(head, 3);
  while (ans)
  {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
  return 0;
}
