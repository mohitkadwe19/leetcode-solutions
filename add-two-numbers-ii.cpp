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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    stack<int> s1, s2;

    while (l1 != NULL)
    {
      s1.push(l1->val);
      l1 = l1->next;
    }
    while (l2 != NULL)
    {
      s2.push(l2->val);
      l2 = l2->next;
    }

    ListNode *result = new ListNode();
    int carry = 0;
    int sum = 0;
    while (!s1.empty() || !s2.empty())
    {
      if (!s1.empty())
      {
        sum += s1.top();
        s1.pop();
      }
      if (!s2.empty())
      {
        sum += s2.top();
        s2.pop();
      }
      result->val = sum % 10;
      carry = sum / 10;

      ListNode *newNode = new ListNode(carry);
      newNode->next = result;
      result = newNode;
      sum = carry;
    }

    if (carry == 0)
    {
      return result->next;
    }
    return result;
  }
};

int main()
{
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);
  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);
  Solution sol;
  ListNode *ans = sol.addTwoNumbers(l1, l2);
  while (ans != nullptr)
  {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
  return 0;
}