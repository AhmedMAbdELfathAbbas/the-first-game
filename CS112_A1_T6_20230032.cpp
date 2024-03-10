/*
Program:
Connect-4 is a two-player strategy game where the objective is to be the first to connect four of 
your own symbols (either "X" or "O") in a row, either horizontally, vertically, or diagonally on a 7x6 grid.
The game is played by dropping tokens from the top of the columns, with the tokens falling to 
the lowest available position within the chosen column.
=============================================================================================================
Author:
Name : Ahmed Mohamed Abd El Fatah Mohamed
Section : ---------
ID : 20230032
============================================================================================================
Version : 5

Date : 2024/3/2
*/

#include <iostream>
#include <windows.h>
using namespace std;
const int rows = 6;
const int columns = 7;
int flag = 0;
char player = 'X';
char matrix[6][7] = {
    ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' '
};

// Function to display the game board
void shape()
{
    if (flag > 0)
    {
        system("cls");  // Clears the console screen
    }
    
    cout << "-----------------" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << rows - i << " " << "|";
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << "|";
        }
        cout << endl;
    }
    cout << "   ";
    for (int i = 1; i <= columns; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin()
{
    // Check horizontally
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= columns - 4; j++)
        {
            if (matrix[i][j] == player &&
                matrix[i][j + 1] == player &&
                matrix[i][j + 2] == player &&
                matrix[i][j + 3] == player)
            {
                return true;
            }
        }
    }

    // Check vertically
    for (int i = 0; i <= rows - 4; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (matrix[i][j] == player &&
                matrix[i + 1][j] == player &&
                matrix[i + 2][j] == player &&
                matrix[i + 3][j] == player)
            {
                return true;
            }
        }
    }

    // Check diagonally (from bottom-left to top-right)
    for (int i = 0; i <= rows - 4; i++)
    {
        for (int j = 0; j <= columns - 4; j++)
        {
            if (matrix[i][j] == player &&
                matrix[i + 1][j + 1] == player &&
                matrix[i + 2][j + 2] == player &&
                matrix[i + 3][j + 3] == player)
            {
                return true;
            }
        }
    }

    // Check diagonally (from top-left to bottom-right)
    for (int i = 3; i < rows; i++)
    {
        for (int j = 0; j <= columns - 4; j++)
        {
            if (matrix[i][j] == player &&
                matrix[i - 1][j + 1] == player &&
                matrix[i - 2][j + 2] == player &&
                matrix[i - 3][j + 3] == player)
            {
                return true;
            }
        }
    }

    return false;
}

// Function to place a player's symbol in a column
void replace(int column)
{
    for (int i = rows - 1; i >= 0; i--)
    {
        if (matrix[i][column] == ' ')
        {
            matrix[i][column] = player;
            break;
        }
    }
}

int main()
{
    cout << "\nwelcome to Connect- 4 game\n";
    cout << "\nThe goal is for a player to connect four of their symbols, either (X) or (O)\n\n";
    while (true)
    {
        shape();  // Display the game board

        int column;
        cout << "Enter the number of column(1-7), player:( " << player << " )\n";
        cin >> column;

        // Check if the move is valid and update the board
        if (column >= 1 && column <= columns && matrix[0][column - 1] == ' ')
        {
            replace(column - 1);

            // Check if the current player has won
            if (checkWin())
            {
                shape();
                cout << "Player " << player << " wins" << endl;
                break;
            }
        }
        else
        {
            cout << "Invalid move. Please try again." << endl;
        }

        // Switch to the other player for the next turn
        if (player == 'X')
        {
            player = 'O';
        }
        else if (player == 'O')
        {
            player = 'X';
        }
        flag++ ;
    }

    return 0;
}
