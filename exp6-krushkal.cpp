#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
  return a[2] < b[2]; // Sort edges by weight
}

void makeSet(vector<int> &parent, vector<int> &rank, int n) {
  for (int i = 0; i < n; i++) {
    parent[i] = i; // Each node is its own parent (initially)
    rank[i] = 0;   // Initialize rank as 0
  }
}

// Find the parent (with path compression)
int findParent(vector<int> &parent, int node) {
  if (parent[node] == node) {
    return node;
  }
  return parent[node] = findParent(parent, parent[node]);
}

// Union by rank
void Union(int u, int v, vector<int> &parent, vector<int> &rank) {
  u = findParent(parent, u);
  v = findParent(parent, v);
  if (rank[u] < rank[v]) {
    parent[u] = v;
  } else if (rank[v] < rank[u]) {
    parent[v] = u;
  } else {
    parent[v] = u;
    rank[u]++;
  }
}


int MinimumSpanningTree(vector<vector<int>> &edges, int n) {
  sort(edges.begin(), edges.end(), cmp); // Sort edges based on weight
  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent, rank, n); 
  int minWeight = 0;
  for (int i = 0; i < edges.size(); i++) {
    int u = findParent(parent, edges[i][0]); // Find parent of u
    int v = findParent(parent, edges[i][1]); // Find parent of v
    int wt = edges[i][2];                    // Get weight of the edge
    if (u != v) // If u and v are in different sets, take the edge
    {
      minWeight += wt;
      Union(u, v, parent, rank); // Union the sets of u and v
    }
  }
  return minWeight; // Return the total weight of the MST
}

int main() {

 
  int n = 9; // Number of vertices
  vector<vector<int>> edges = {{0, 1, 4},  {0, 7, 8},  {1, 2, 8}, {1, 7, 11},
                               {2, 3, 7},  {2, 5, 4},  {2, 8, 2}, {3, 4, 9},
                               {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1},
                               {6, 8, 6},  {7, 8, 7}};
  int minWeight = MinimumSpanningTree(edges, n);
  cout << "Minimum weight of the spanning tree: " << minWeight << endl;
  return 0;
}