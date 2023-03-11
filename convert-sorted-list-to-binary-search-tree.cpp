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

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  TreeNode *sortedListToBST(ListNode *head)
  {
    if (head == nullptr)
    {
      return nullptr;
    }
    if (head->next == nullptr)
    {
      return new TreeNode(head->val);
    }
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;
    while (fast != nullptr && fast->next != nullptr)
    {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = nullptr;
    TreeNode *root = new TreeNode(slow->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    return root;
  }
};

int main()
{
  ListNode *head = new ListNode(-10);
  head->next = new ListNode(-3);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(5);
  head->next->next->next->next = new ListNode(9);

  Solution *sol = new Solution();
  TreeNode *root = sol->sortedListToBST(head);
  return 0;
}