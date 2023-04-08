#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
  int val;
  vector<Node *> neighbors;
  Node()
  {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val)
  {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors)
  {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution
{
public:
  Node *cloneGraph(Node *node)
  {
    if (node == NULL)
      return NULL;
    unordered_map<Node *, Node *> m;
    queue<Node *> q;
    q.push(node);
    Node *newNode = new Node(node->val);
    m[node] = newNode;
    while (!q.empty())
    {
      Node *temp = q.front();
      q.pop();
      for (auto n : temp->neighbors)
      {
        if (m.find(n) == m.end())
        {
          Node *newNode = new Node(n->val);
          m[n] = newNode;
          q.push(n);
        }
        m[temp]->neighbors.push_back(m[n]);
      }
    }
    return m[node];
  }
};

int main()
{
  Node *node = new Node(1);
  node->neighbors.push_back(node);
  Node *node2 = new Node(2);
  node->neighbors.push_back(node2);
  Node *node3 = new Node(3);
  node->neighbors.push_back(node3);
  Node *node4 = new Node(4);
  Solution s;
  Node *node5 = s.cloneGraph(node);
  cout << node5->val << endl;
  return 0;
}