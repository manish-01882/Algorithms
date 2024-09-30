#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

const int INF = INT_MAX; // Represent infinity
const int N = 9;         // Number of cities

int main() {


    // Adjacency matrix for graph (weights of phone lines between cities)
    int weight[N][N] = {
        {INF, 4,   INF, INF, INF, INF, INF, 8,   INF},
        {4,   INF, 8,   INF, INF, INF, INF, 11,  INF},
        {INF, 8,   INF, 7,   INF, 4,   INF, INF, 2},
        {INF, INF, 7,   INF, 9,   14,  INF, INF, INF},
        {INF, INF, INF, 9,   INF, 10,  INF, INF, INF},
        {INF, INF, 4,   14,  10,  INF, 2,   INF, INF},
        {INF, INF, INF, INF, INF, 2,   INF, 1,   6},
        {8,   11,  INF, INF, INF, INF, 1,   INF, 7},
        {INF, INF, 2,   INF, INF, INF, 6,   7,   INF}
    };

    // Variables
    vector<bool> visited(N, false);      // To mark visited cities
    vector<int> distance(N, INF);        // To store the minimum cost to each city
    vector<int> nbr(N, -1);              // To store the nearest neighbor for each city
    vector<pair<int, int>> edges;        // To store the selected edges in MST
    int src = 0;                         // Start from city 0
    visited[src] = true;                 // Mark source as visited

    // Initialize distances from the source
    for (int j = 0; j < N; j++) {
        nbr[j] = 0;
        distance[j] = weight[src][j];
    }

    // Prim's Algorithm
    for (int i = 1; i < N; i++) {
        int min = INF, index = -1;

        // Find the next vertex to include in MST
        for (int j = 0; j < N; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                index = j;
            }
        }

        // Add the selected edge to the MST
        edges.push_back({nbr[index], index});
        visited[index] = true;

        // Update distances to the remaining cities
        for (int k = 0; k < N; k++) {
            if (!visited[k] && weight[index][k] < distance[k]) {
                distance[k] = weight[index][k];
                nbr[k] = index;
            }
        }
    }

    // Output the selected edges and the cost of each
    cout << "Path selected for phone lines [city1 -> city2] \t\t Cost\n";
    for (int i = 0; i < edges.size(); i++) {
        cout << "[" << edges[i].first << " -> " << edges[i].second << "] \t\t\t\t " << distance[edges[i].second] << "\n";
    }

    // Calculate the total cost
    int totalCost = 0;
    for (int i = 1; i < N; i++) {
        totalCost += distance[i];
    }

    // Output the total minimum cost
    cout << "Minimum cost of connecting all cities through phone line is : " << totalCost << endl;

    return 0;
}
