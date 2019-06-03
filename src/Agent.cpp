#include <iostream>
#include "Agent.h"
using namespace std;

Agent::Agent(Board &b, int p, int d = 3) 
{
	depth = d;
	board = &b;
	player = p;
}

int Agent::otherPlayer(int p)
{
	if (p == 1)
	{
		return 2;
	} 
	if (p == 2)
	{
		return 1;
	}
	return 0;
}

int Agent::evaluateLine(int first, int second, int third) {
	int other = otherPlayer(player);
	int score = 0;
	// First Cell
	if (first == player)
	{
		score = 1;
	}
	else if (first == other) {
		score = -1;
	}
	// Second Cell
	if (second == player) 
	{
		if (score == 1)
		{
			score = 10;
		}
		else if(score == -1)
		{
			return 0;
		}
		else 
		{
			score = 1;
		}
	}
	else if (second == other) 
	{
		if (score == -1)
		{
			score = -10;
		}
		else if(score == 1)
		{
			return 0;
		}
		else 
		{
			score = -1;
		}
	}
	// Third Cell
	if (third == player) 
	{
		if (score > 0) 
		{
			score *= 10;
		}
		else if(score < 0)
		{
			return 0;
		}
		else 
		{
			score = 1;
		}
	}
	else if (third == other)
	{
		if (score < 0)
		{
			score *= 10;
		}
		else if(score > 1)
		{
			return 0;
		}
		else
		{
			score = -1;
		}
	}
	return score;
}

int Agent::getBoardScore(Board &b) 
{
	int other = otherPlayer(player);
	if (b.isGameCompleted()) {
		if (b.winner == player) {
		return 10000;
		}
		else if(b.winner == otherPlayer(player)) {
			return -10000;
		} 
		else 
		{
			return 0;
		}
	}
	
	int score = 0;
	for (int row = 0; row < 3; row ++) 
	{
		score += evaluateLine(b.getItem(row, 0), b.getItem(row, 1), b.getItem(row, 2));
	}
	// go through all columns
	for (int col = 0; col < 3; col ++) 
	{
		score += evaluateLine(b.getItem(0, col), b.getItem(1, col), b.getItem(2, col));
	}
	// go through criss/cross
	score += evaluateLine(b.getItem(0, 0), b.getItem(1, 1), b.getItem(2, 2));
	score += evaluateLine(b.getItem(0, 2), b.getItem(1, 1), b.getItem(2, 0));
	return score;
	// return 0;

}

int Agent::alphabeta(Board &b, int d, int alpha, int beta, int currentPlayer)
{
	if (d == 0 || b.isGameCompleted()) {
		return getBoardScore(b);
	}
	if (currentPlayer == player) 
	{
		int value = -1000000;
		for(int i = 0; i < 3; i ++)
		{
			for(int j = 0; j < 3; j ++)
			{
				if(b.isValidPlacement(i, j)) 
				{
					b.place(i, j);
					value = max(value, alphabeta(b, d - 1, alpha, beta, otherPlayer(currentPlayer)));
					alpha = max(alpha, value);
					b.reset(i, j);
					if (alpha >= beta)
					{
						break;
					}
				}
			}
		}
		return value;
	}
	else 
	{
		int value = 1000000;
		for(int i = 0; i < 3; i ++)
		{
			for(int j = 0; j < 3; j ++)
			{
				if(b.isValidPlacement(i, j)) 
				{
					b.place(i, j);
					value = min(value, alphabeta(b, d - 1, alpha, beta, otherPlayer(currentPlayer)));
					alpha = min(alpha, value);
					b.reset(i, j);
					if (alpha >= beta)
					{
						break;
					}
				}
			}
		}
		return value;
	}
}

pair<int, int> Agent::bestPlay(Board &b) {
	int alpha = -1000000;
	int beta = 1000000;

	pair<int, int> bestPair = make_pair<int, int>(-1, -1);
	int bestValue = -1000000;
	for(int i = 0; i < 3; i ++)
	{
		for(int j = 0; j < 3; j ++)
		{
			if(b.isValidPlacement(i, j)) 
			{
				b.place(i, j);
				int value = alphabeta(b, depth, alpha, beta, otherPlayer(player));
				// cout << i << ", " << j << "\n";
				// cout << value << "\n";
				if (value > bestValue)
				{
					bestPair = make_pair<int, int>(i, j);
					bestValue = value;
				}
				b.reset(i, j);
			}
		}
	}
	return bestPair;
}

void Agent::playMove() {
	// figure out best play
	if (board->getCurrentPlayer() == player) {
		pair<int, int> selectedBestPlay = bestPlay(*board);
		int x = get<0>(selectedBestPlay);
		int y = get<1>(selectedBestPlay);
		if (x != -1 && y != -1)
		{	
			board->place(x, y);
		}
		
	}
}
