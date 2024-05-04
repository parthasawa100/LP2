#include <bits/stdc++.h>
using namespace std;
const vector<int> goalState = {1, 2, 3, 4, 5, 6, 7, 8, 0};
const int puzzleSize = 9;
struct PuzzleState
{
    vector<int> board;
    int cost;
    int heuristic;
    int emptyPos;
    vector<PuzzleState *> successors;
    PuzzleState *parent;
    PuzzleState(vector<int> _board, int _emptyPos,
                PuzzleState *_parent) : board(_board), emptyPos(_emptyPos),
                                        parent(_parent)
    {
        cost = parent ? parent->cost + 1 : 0;
        heuristic = calculateHeuristic();
    }
    int calculateHeuristic()
    {
        int h = 0;
        for (int i = 0; i < puzzleSize; ++i)
        {
            if (board[i] != 0 && board[i] != goalState[i])
            {
                int targetIndex = find(goalState.begin(), goalState.end(),
                                       board[i]) -
                                  goalState.begin();
                h +=
                    abs(i / 3 - targetIndex / 3) + abs(i % 3 - targetIndex % 3);
            }
        }
        return h;
    }
    bool isGoal()
    {
        return board == goalState;
    }
    void generateSuccessors()
    {
        successors.clear();
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i)
        {
            int newX = emptyPos / 3 + dx[i];
            int newY = emptyPos % 3 + dy[i];
            if (newX >= 0 && newX < 3 && newY >= 0 && newY < 3)
            {
                vector<int> newBoard = board;
                swap(newBoard[emptyPos], newBoard[newX * 3 + newY]);
                successors.push_back(new PuzzleState(newBoard, newX * 3 + newY,
                                                     this));
            }
        }
    }
};
struct CompareCost
{
    bool operator()(PuzzleState *a, PuzzleState *b)
    {
        return a->cost + a->heuristic > b->cost + b->heuristic;
    }
};
vector<vector<int>>
solvePuzzle(vector<int> initial)
{
    priority_queue<PuzzleState *, vector<PuzzleState *>,
                   CompareCost>
        openSet;
    set<vector<int>> closedSet;
    int emptyPos =
        find(initial.begin(), initial.end(), 0) - initial.begin();
    PuzzleState *initialState = new PuzzleState(initial, emptyPos, nullptr);
    openSet.push(initialState);

    while (!openSet.empty())
    {
        PuzzleState *current = openSet.top();
        openSet.pop();
        if (current->isGoal())
        {
            vector<vector<int>> solution;
            while (current != nullptr)
            {
                solution.push_back(current->board);
                current = current->parent;
            }
            reverse(solution.begin(), solution.end());
            return solution;
        }
        current->generateSuccessors();
        closedSet.insert(current->board);

        for (PuzzleState *successor : current->successors)
        {
            if (closedSet.find(successor->board) == closedSet.end())
            {
                openSet.push(successor);
            }
        }
    }
    return {};
}

void printBoard(const vector<int> &board)
{
    for (int i = 0; i < puzzleSize; ++i)
    {
        cout << board[i] << " ";
        if (i % 3 == 2)
            cout << endl;
    }
    cout << endl;
}
int main()
{
    vector<int> initial = {1, 2, 3, 4, 0, 5, 7, 8, 6};

    cout << "Initial State:" << endl;
    printBoard(initial);

    vector<vector<int>> solution = solvePuzzle(initial);

    if (!solution.empty())
    {
        cout << "Solution:" << endl;
        for (const auto &board : solution)
        {
            printBoard(board);
        }
    }
    else
    {
        cout << "No solution found!" << endl;
    }
    return 0;
}