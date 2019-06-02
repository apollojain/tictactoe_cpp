#include <iostream>
#include "Board.h"
using namespace std;

Board::Board() 
{
	gameCompleted = false;
	for (int i=0; i < 3; i++)
	{
	    for (int j=0; j < 3; j++)
	    {
	        board[i][j] = 0;
	    }
	}
	currentPlayer = 1;
}

void Board::changePlayer() 
{
	if (currentPlayer == 1) 
	{
		currentPlayer = 2;
	} 
	else 
	{
		currentPlayer = 1;
	}
}

int Board::getItem(int x, int y) 
{
	// cout << board[x][y];
	// cout << "\n";
	return board[x][y];
}

void Board::setItem(int x, int y, int val) 
{
	board[x][y] = val;
}

void Board::checkGameComplete() 
{
	// go through all rows
	for (int row = 0; row < 3; row ++) 
	{
		if (getItem(row, 0) != 0) 
		{
			if (getItem(row, 0) == getItem(row, 1) && getItem(row, 1) == getItem(row, 2)) 
			{
				winner = getItem(row, 0);
				gameCompleted = true;
			}
		}
	}
	// go through all columns
	for (int col = 0; col < 3; col ++) 
	{
		if (getItem(0, col) != 0) 
		{
			if (getItem(0, col) == getItem(1, col) && getItem(1, col) == getItem(2, col)) 
			{
				winner = getItem(0, col);
				gameCompleted = true;
			}
		}
	}
	// go through criss/cross
	if (getItem(0, 0) != 0 && getItem(0, 0) == getItem(1, 1) && getItem(1, 1) == getItem(2, 2)) 
	{
		winner = getItem(0, 0);
		gameCompleted = true;
	}
	if (getItem(2, 0) != 0 && getItem(2, 0) == getItem(1, 1) && getItem(1, 1) == getItem(0, 2)) 
	{
		winner = getItem(2, 0);
		gameCompleted = true;
	}
}

bool Board::isValidPlacement(int x, int y) 
{

	if (!isGameCompleted() && getItem(x, y) == 0) {
		return true;
	} else {
		return false;
	}
}

bool Board::place(int x, int y) 
{
	if (isValidPlacement(x, y)) 
	{
		setItem(x, y, currentPlayer);
		checkGameComplete();
		changePlayer();
		return true;
	} 
	else 
	{
		return false;
	}
}

bool Board::isGameCompleted() 
{
	return gameCompleted;
}

void Board::printBoard() 
{
	int width = 3, height = 3;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
        	char c = '-';
        	int val = getItem(i, j);
        	if (val == 1) 
        	{
        		c = 'X';
        	} 
        	if (val == 2) 
        	{
        		c = 'O';
        	}
            cout << c << ' ';
        }
        std::cout << std::endl;
    }
}

void Board::play() 
{
	// start by having infinite loop telling if you've won or lost
	while (!isGameCompleted())
	{
		// take in two numbers
		int x, y;
		cout << "Enter your row and column (first row then column, 1 to 3)\n";
		cin >> x >> y;
		while (!place(x - 1, y - 1))
		{
			cout << "Invalid entry. Enter your row and column (first row then column, 1 to 3)\n";
			cin >> x >> y;
		}
		printBoard();
	}
}
