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
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    ListNode *head = NULL;
    ListNode *tail = NULL;
    ListNode *minNode = NULL;
    int minIndex = -1;
    int count = 0;
    while (true)
    {
      minNode = NULL;
      minIndex = -1;
      for (int i = 0; i < lists.size(); i++)
      {
        if (lists[i] != NULL)
        {
          if (minNode == NULL)
          {
            minNode = lists[i];
            minIndex = i;
          }
          else if (minNode->val > lists[i]->val)
          {
            minNode = lists[i];
            minIndex = i;
          }
        }
      }
      if (minIndex == -1)
      {
        break;
      }
      if (head == NULL)
      {
        head = minNode;
        tail = minNode;
      }
      else
      {
        tail->next = minNode;
        tail = tail->next;
      }
      lists[minIndex] = lists[minIndex]->next;
    }
    return head;
  }
};

int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(4);
  head->next->next = new ListNode(5);

  ListNode *head2 = new ListNode(1);
  head2->next = new ListNode(3);
  head2->next->next = new ListNode(4);

  ListNode *head3 = new ListNode(2);
  head3->next = new ListNode(6);

  vector<ListNode *> lists;
  lists.push_back(head);
  lists.push_back(head2);
  lists.push_back(head3);

  Solution *sol = new Solution();
  ListNode *res = sol->mergeKLists(lists);

  while (res != NULL)
  {
    cout << res->val << " ";
    res = res->next;
  }
  return 0;
}