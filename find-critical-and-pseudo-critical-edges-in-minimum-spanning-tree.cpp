#include <bits/stdc++.h>
using namespace std;

// UnionFind class for implementing disjoint-set data structure
class UnionFind
{
public:
  vector<int> parent;

  // Constructor to initialize parent array
  UnionFind(int n)
  {
    parent.resize(n);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i; // Each element is initially its own parent
    }
  }

  // Find operation with path compression
  int findParent(int p)
  {
    // If the current element is its own parent, return it
    // Otherwise, recursively find and update the parent, then return
    return parent[p] == p ? p : parent[p] = findParent(parent[p]);
  }

  // Union operation to merge two sets by updating parent
  void Union(int u, int v)
  {
    int pu = findParent(u), pv = findParent(v);
    parent[pu] = pv; // Make one element's parent point to the other's parent
  }
};

// Solution class containing the main algorithm
class Solution
{
private:
  // Function to calculate the Minimum Spanning Tree weight with an optional excluded edge
  int MST(int &n, vector<vector<int>> &edges, int block, int e)
  {
    UnionFind uf(n);
    int w = 0;

    // Include the excluded edge if specified
    if (e != -1)
    {
      w += edges[e][2];                   // Add the weight of the excluded edge
      uf.Union(edges[e][0], edges[e][1]); // Merge the vertices of the excluded edge
    }

    // Iterate through edges and build the MST
    for (int i = 0; i < edges.size(); i++)
    {
      if (i == block)
        continue; // Skip the blocked edge
      if (uf.findParent(edges[i][0]) == uf.findParent(edges[i][1]))
        continue; // Skip if in same set

      uf.Union(edges[i][0], edges[i][1]); // Merge vertices of the current edge
      w += edges[i][2];                   // Add the weight of the current edge to the MST weight
    }

    // Check if all vertices are in the same set (MST is connected)
    for (int i = 0; i < n; i++)
    {
      if (uf.findParent(i) != uf.findParent(0))
        return INT_MAX; // Not connected, return a large value
    }

    return w; // Return the weight of the MST
  }

public:
  // Comparator function for sorting edges based on weight
  static bool cmp(vector<int> &a, vector<int> &b)
  {
    return a[2] < b[2]; // Compare edges based on weight
  }

  // Main function to find critical and pseudo-critical edges
  vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
  {
    vector<int> c, psc;

    // Attach edge index to each edge for identification after sorting
    for (int i = 0; i < edges.size(); i++)
    {
      edges[i].push_back(i);
    }

    // Sort the edges in ascending order of weight
    sort(edges.begin(), edges.end(), cmp);

    // Calculate the weight of the minimum spanning tree (MST)
    int mst = MST(n, edges, -1, -1);

    // Iterate through edges to find critical and pseudo-critical edges
    for (int i = 0; i < edges.size(); i++)
    {
      // Check if adding the edge would result in a lower MST weight (critical edge)
      if (mst < MST(n, edges, i, -1))
      {
        c.push_back(edges[i][3]); // Add the edge index to the critical list
      }
      // Check if the edge can be part of the MST with the same weight (pseudo-critical edge)
      else if (mst == MST(n, edges, -1, i))
      {
        psc.push_back(edges[i][3]); // Add the edge index to the pseudo-critical list
      }
    }

    // Return the lists of critical and pseudo-critical edges
    return {c, psc};
  }
};

int main()
{
  Solution s;
  vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 1}, {2, 3, 4}, {3, 4, 2}, {3, 5, 2}, {4, 5, 2}};
  vector<vector<int>> ans = s.findCriticalAndPseudoCriticalEdges(6, edges);
  for (auto i : ans)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}