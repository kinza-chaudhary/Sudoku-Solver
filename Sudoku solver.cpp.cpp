#include <iostream>
using namespace std;

// Check if placing num is valid
bool isSafe(int board[9][9], int row, int col, int num)
{
    // Check row
    for (int x = 0; x < 9; x++)
    {
        if (board[row][x] == num)
            return false;
    }

    // Check column
    for (int x = 0; x < 9; x++)
    {
        if (board[x][col] == num)
            return false;
    }

    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i + startRow][j + startCol] == num)
                return false;
        }
    }

    return true;
}

// Backtracking function
bool solveSudoku(int board[9][9])
{
    int row, col;
    bool empty = false;

    // Find an empty cell
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (board[row][col] == 0)
            {
                empty = true;
                break;
            }
        }

        if (empty)
            break;
    }

    // No empty cell means solved
    if (!empty)
        return true;

    // Try numbers 1-9
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;

            if (solveSudoku(board))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

// Print Sudoku board
void printBoard(int board[9][9])
{
    cout << "\nSolved Sudoku:\n\n";

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int board[9][9];

    cout << "Enter Sudoku Puzzle (use 0 for empty cells):\n";

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    if (solveSudoku(board))
    {
        printBoard(board);
    }
    else
    {
        cout << "\nNo solution exists.\n";
    }

    return 0;
}


