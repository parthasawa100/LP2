#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class NQueens {
private:
    int n;
    vector<vector<int>> board;

    bool isSafe(int row, int col) {
        // Check if no queen is present in the same row on the left side
        for (int i = 0; i < col; ++i)
            if (board[row][i] == 1)
                return false;

        // Check upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
            if (board[i][j] == 1)
                return false;

        // Check lower diagonal on left side
        for (int i = row, j = col; i < n && j >= 0; ++i, --j)
            if (board[i][j] == 1)
                return false;

        return true;
    }

    bool solveBacktracking(int col) {
        if (col >= n) {
            printBoard();
            return true;
        }

        bool res = false;
        for (int i = 0; i < n; ++i) {
            if (isSafe(i, col)) {
                board[i][col] = 1;
                res = solveBacktracking(col + 1) || res;
                board[i][col] = 0;
            }
        }
        return res;
    }

    bool solveBranchAndBound(int col) {
        if (col >= n) {
            printBoard();
            return true;
        }

        bool res = false;
        for (int i = 0; i < n; ++i) {
            if (isSafe(i, col)) {
                board[i][col] = 1;
                if (solveBranchAndBound(col + 1)) {
                    res = true;
                    // No need to explore further if we found a solution
                    break;
                }
                board[i][col] = 0;
            }
        }
        return res;
    }

    void printBoard() const {
        for (const auto& row : board) {
            for (int cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

public:
    NQueens(int size) : n(size) {
        board.assign(n, vector<int>(n, 0));
    }

    void solveBacktracking() {
        solveBacktracking(0);
    }

    void solveBranchAndBound() {
        solveBranchAndBound(0);
    }
};

int main() {
    int n = 4; 
    NQueens nQueens(n);
    cout << "Solutions using Backtracking:\n";
    nQueens.solveBacktracking();
    cout << "Solutions using Branch and Bound:\n";
    nQueens.solveBranchAndBound();

    return 0;
}
