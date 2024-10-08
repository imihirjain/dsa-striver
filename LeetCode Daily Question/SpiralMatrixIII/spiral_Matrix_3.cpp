#include <bits/stdc++.h>
using namespace std;


// You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

// You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

// Return an array of coordinates representing the positions of the grid in the order you visited them.

// Input: rows = 1, cols = 4, rStart = 0, cStart = 0
// Output: [[0,0],[0,1],[0,2],[0,3]]

// Input: rows = 5, cols = 6, rStart = 1, cStart = 4
// Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]


vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
{
    vector<vector<int>> result;
    int totalCells = rows * cols;
    result.push_back({rStart, cStart});
    int steps = 1; // Number of steps to take in the current direction

    // Directions: right, down, left, up
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dir = 0; // Starting with 'right'

    while (result.size() < totalCells)
    {
        for (int i = 0; i < 2; ++i)
        { // We change direction after every two moves
            for (int j = 0; j < steps; ++j)
            {
                rStart += directions[dir][0];
                cStart += directions[dir][1];
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                {
                    result.push_back({rStart, cStart});
                }
            }
            dir = (dir + 1) % 4; // Change direction
        }
        ++steps; // Increase the step length
    }

    return result;
}

int main()
{
    return 0;
}
