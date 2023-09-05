#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val)
  {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    Node *new_head = nullptr;
    Node *temp = head;
    map<Node *, Node *> mp;
    while (temp != nullptr)
    {
      Node *newNode = new Node(temp->val);
      mp[temp] = newNode;
      temp = temp->next;
    }

    temp = head;
    while (temp != nullptr)
    {
      Node *node = mp[temp];
      node->next = mp[temp->next];
      node->random = mp[temp->random];
      temp = temp->next;
    }

    return mp[head];
  }
};

int main()
{
  Node *head = NULL;
  head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  Solution s;
  cout << s.copyRandomList(head) << endl;
  return 0;
}
