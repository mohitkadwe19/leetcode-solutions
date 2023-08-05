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
  int calculateGCD(int a, int b)
  {
    while (b)
    {
      int temp = b;
      b = a % b;
      a = temp;
    }
    return a;
  }
  ListNode *insertGreatestCommonDivisors(ListNode *head)
  {
    ListNode *current = head;

    while (current && current->next)
    {
      int gcd = calculateGCD(current->val, current->next->val);
      ListNode *newNode = new ListNode(gcd);
      newNode->next = current->next;
      current->next = newNode;
      current = current->next->next;
    }
    return head;
  }
};

int main()
{
  Solution s;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);

  cout << s.insertGreatestCommonDivisors(head);
  return 0;
}