#include <iostream>
#include "Agent.h"

Agent::Agent(Board &b, int p, int d = 3) 
{
	depth = d;
	board = b;
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

int Agent::alphabeta(Board &b, int depth, int alpha, int beta, int maximizingPlayer)
{
	return 0;
}

std::pair<int, int> Agent::bestPlay(Board &b) {
	int alpha = -1000000;
	int beta = 1000000;

	std::pair<int, int> bestPair = std::make_pair<int, int>(-1, -1);
	int bestValue = -1000000;
	for(int i = 0; i < 3; i ++)
	{
		for(int j = 0; j < 3; j ++)
		{
			if(board.isValidPlacement(i, j)) 
			{
				board.place(i, j);
				int value = alphabeta(board, depth, alpha, beta, player);
				if (value > bestValue)
				{
					bestPair = std::make_pair<int, int>(i, j);
					bestValue = value;
				}
				board.reset(i, j);
			}
		}
	}
	return bestPair;
}

void Agent::play() {
	// figure out best play
	if (board.getCurrentPlayer() == player) {
		std::pair<int, int> selectedBestPlay = bestPlay(board);
		int x = std::get<0>(selectedBestPlay);
		int y = std::get<1>(selectedBestPlay);
		if (x != -1 && y != -1)
		{
			board.place(x, y);
		}
		
	}
}
