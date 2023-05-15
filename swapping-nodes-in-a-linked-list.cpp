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
  ListNode *swapNodes(ListNode *head, int k)
  {
    ListNode *temp = head;
    int len = 0;
    while (temp != nullptr)
    {
      len++;
      temp = temp->next;
    }
    int first = k, second = len - k + 1;
    if (first == second)
      return head;
    ListNode *firstNode = nullptr, *secondNode = nullptr;
    temp = head;
    int i = 1;
    while (temp != nullptr)
    {
      if (i == first)
        firstNode = temp;
      if (i == second)
        secondNode = temp;
      temp = temp->next;
      i++;
    }
    swap(firstNode->val, secondNode->val);
    return head;
  }
};

int main()
{
  ListNode *head = new ListNode(1);
  ListNode *temp = head;
  for (int i = 2; i <= 5; i++)
  {
    temp->next = new ListNode(i);
    temp = temp->next;
  }
  Solution sol;
  ListNode *ans = sol.swapNodes(head, 2);
  while (ans != nullptr)
  {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
  return 0;
};