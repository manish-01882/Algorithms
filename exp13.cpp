#include <iostream>
#include <vector>

#define N 8

using namespace std;

void printSolution(vector<vector<int>> &board) {
    cout << "Solution of 8 Queen problem using backtracking is:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<int>> &board, int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solveNQUtil(vector<vector<int>> &board, int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

bool solveNQ() {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQUtil(board, 0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    printSolution(board);
    return true;
}

int main() {
    solveNQ();
    return 0;
}
