#include <iostream>
#include "Board.h"

class Agent {
public:
	int depth;
	Board board;
	int player;
	Agent(Board &b, int p, int d);
	int otherPlayer(int p); 
	int alphabeta(Board &b, int depth, int alpha, int beta, int maximizingPlayer);
	std::pair<int, int> bestPlay(Board &b);
	void play();
};