#include <iostream>
#include "Game.h"
using namespace std;

void Game::play() 
{
	// start by having infinite loop telling if you've won or lost
	char ai;
	Board b;

	
	cout << "Welcome to tic tac toe. Would you like to play with an AI? (y or n)\n";
	cin >> ai;
	while(ai != 'y' && ai != 'n')
	{
		cout << "That is an invalid response. Would you like to play with an AI? (y or n)\n";
		cin >> ai;
	}
	Agent a1(b, 2, 3);

	while (!b.isGameCompleted())
	{
		// take in two numbers
		int x, y;
		cout << "(P" << b.currentPlayer << ") Enter your row and column (first row then column, 1 to 3)\n";
		cin >> x >> y;
		while (!b.place(x - 1, y - 1))
		{
			cout << "(P" << b.currentPlayer << ") Invalid entry. Enter your row and column (first row then column, 1 to 3)\n";
			cin >> x >> y;
		}
		b.printBoard();
		if (!b.isGameCompleted() && ai == 'y')
		{
			cout << "AI Plays\n";
			a1.playMove();
			b.printBoard();
		}
	}
	if(b.winner == 0) 
	{
		cout << "The game is over. It is a draw.\n";
	}
	else
	{
		cout << "The game is over. Player " <<  b.winner << " is the winner.\n";
	}
	
}