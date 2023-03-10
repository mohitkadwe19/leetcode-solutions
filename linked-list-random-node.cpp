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
private:
  ListNode *head;

public:
  Solution(ListNode *head)
  {
    this->head = head;
  }

  int getRandom()
  {
    int count = 0;
    int result = 0;
    ListNode *current = head;
    while (current)
    {
      count++;
      if (rand() % count == 0)
      {
        result = current->val;
      }
      current = current->next;
    }
    return result;
  }
};

int main()
{

  return 0;
}