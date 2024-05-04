#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

// Structure to represent each state of the puzzle
struct PuzzleState
{
    vector<vector<int>> board; // The board configuration
    int g, h;                  // g(n): cost to reach this state, h(n): heuristic value

    PuzzleState(const vector<vector<int>> &b, int g_val, int h_val)
        : board(b), g(g_val), h(h_val) {}

    // Function to check if two states are equal
    bool operator==(const PuzzleState &other) const
    {
        return board == other.board;
    }

    // Function to compare two states for ordering in sets
    bool operator<(const PuzzleState &other) const
    {
        return board < other.board;
    }
};

// Function to calculate the Manhattan distance heuristic
int manhattanDistance(const vector<vector<int>> &board)
{
    int distance = 0;
    int n = board.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] != 0)
            {
                int goalX = (board[i][j] - 1) / n;
                int goalY = (board[i][j] - 1) % n;
                distance += abs(i - goalX) + abs(j - goalY);
            }
        }
    }
    return distance;
}

// Function to get the next possible states from the current state
vector<PuzzleState> getNextStates(const PuzzleState &current)
{
    vector<PuzzleState> nextStates;
    int n = current.board.size();
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int x, y;

    // Finding the position of the empty tile (0)
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (current.board[i][j] == 0)
            {
                x = i;
                y = j;
                break;
            }
        }
    }

    // Generating next states by moving the empty tile in all possible directions
    for (int k = 0; k < 4; ++k)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
        {
            vector<vector<int>> newBoard = current.board;
            swap(newBoard[x][y], newBoard[nx][ny]);
            PuzzleState newState(newBoard, current.g + 1, manhattanDistance(newBoard));
            nextStates.push_back(newState);
        }
    }
    return nextStates;
}

// A* algorithm implementation
vector<vector<int>> solvePuzzle(const vector<vector<int>> &initial)
{
    int n = initial.size();
    PuzzleState initialState(initial, 0, manhattanDistance(initial));
    priority_queue<pair<int, PuzzleState>, vector<pair<int, PuzzleState>>, greater<pair<int, PuzzleState>>> pq;
    set<vector<vector<int>>> visited;

    pq.push({initialState.g + initialState.h, initialState});

    while (!pq.empty())
    {
        PuzzleState current = pq.top().second;
        pq.pop();

        if (current.h == 0)
        {
            // Found the goal state
            return current.board;
        }

        visited.insert(current.board);

        vector<PuzzleState> nextStates = getNextStates(current);
        for (const PuzzleState &nextState : nextStates)
        {
            if (visited.find(nextState.board) == visited.end())
            {
                pq.push({nextState.g + nextState.h, nextState});
                visited.insert(nextState.board);
            }
        }
    }

    // No solution found
    return {};
}

// Function to print the puzzle board
void printPuzzle(const vector<vector<int>> &puzzle)
{
    for (const auto &row : puzzle)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> initial = {
        {1, 2, 5},
        {4, 3, 6},
        {0, 7, 8}};

    cout << "Initial Puzzle:" << endl;
    printPuzzle(initial);

    vector<vector<int>> solution = solvePuzzle(initial);

    cout << "\nSolution:" << endl;
    if (!solution.empty())
    {
        printPuzzle(solution);
    }
    else
    {
        cout << "No solution found." << endl;
    }

    return 0;
}
