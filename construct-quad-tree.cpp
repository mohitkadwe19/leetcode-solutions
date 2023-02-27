#include <bits/stdc++.h>
using namespace std;

// Definition for a QuadTree node.
class Node
{
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node()
  {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf)
  {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
  {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution
{
public:
  bool checkvalue(vector<vector<int>> &grid, int x, int y, int n)
  {
    int m = n, val = grid[x][y];
    for (int i = x; i < x + n; i++)
    {
      for (int j = y; j < y + n; j++)
      {
        if (grid[i][j] != val)
        {
          return false;
        }
      }
    }
    return true;
  }

  // Recursively constructs a Quadtree for the input grid.
  void buildQuad(vector<vector<int>> &grid, Node *root, int x, int y, int n)
  {
    // If all elements in the current sub-grid have the same value,
    // mark the current node as a leaf and set its val to the common value.
    if (checkvalue(grid, x, y, n))
    {
      root->isLeaf = true;
      root->val = grid[x][y];
    }
    // If the elements in the current sub-grid have different values,
    // mark the current node as an internal node and recursively construct
    // its four child nodes.
    else
    {
      root->isLeaf = false;
      root->val = 1; // Doesn't matter, since it's an internal node.
      // Construct the top-left child node.
      root->topLeft = new Node();
      buildQuad(grid, root->topLeft, x, y, n / 2);
      // Construct the top-right child node.
      root->topRight = new Node();
      buildQuad(grid, root->topRight, x, y + n / 2, n / 2);
      // Construct the bottom-left child node.
      root->bottomLeft = new Node();
      buildQuad(grid, root->bottomLeft, x + n / 2, y, n / 2);
      // Construct the bottom-right child node.
      root->bottomRight = new Node();
      buildQuad(grid, root->bottomRight, x + n / 2, y + n / 2, n / 2);
    }
  }

  // Constructs the Quadtree for the input grid and returns the root node.
  Node *construct(vector<vector<int>> &grid)
  {
    Node *root = new Node();
    int n = grid.size();            // Assume the grid is square.
    buildQuad(grid, root, 0, 0, n); // Start building the Quadtree from the root node.
    return root;
  }
};

int main()
{
  Solution *sol = new Solution();
  vector<vector<int>> grid = {{0, 1},
                              {1, 0}};
  Node *root = sol->construct(grid);
  cout << root->val << endl;

  return 0;
}