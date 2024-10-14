#include <iostream>
#include <vector>
using namespace std;

const int INF = __INT_MAX__;  

void AllPaths(vector<vector<int>>& cost, vector<vector<int>>& A, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = cost[i][j]; 
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);  
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    
    vector<vector<int>> cost(n, vector<int>(n));
    vector<vector<int>> A(n, vector<int>(n));

    
    cout << "Enter the cost adjacency matrix (use " << INF << " for infinity):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    AllPaths(cost, A, n);

    cout << "The matrix of shortest paths between all pairs of vertices is:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << A[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
