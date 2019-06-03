#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Agent.h"
using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

Board nearCompleteGame() {
	Board b;
	b.place(1, 1);
	b.place(0, 0);
	b.place(1, 0);
	b.place(0, 1);
	return b;
}
void testSimpleGame() 
{
	Board b1;
	// test 1: place at a spot that is 
	cout << "TEST 1: PLACE X AT A GOOD SPOT \n";
	int p1 = b1.currentPlayer;
	cout << (b1.isValidPlacement(0, 0) == true);
	cout << "\n";
	cout << (b1.place(0, 0) == true);
	cout << "\n";
	cout << (p1 == 1);
	cout << "\n";
	b1.printBoard();

	// // test 2: place at a bad spot
	cout << "TEST 2: PLACE O AT A BAD SPOT \n";
	int p2 = b1.currentPlayer;
	cout << (b1.isValidPlacement(0, 0) == false);
	cout << "\n";
	cout << (b1.place(0, 0) == false);
	cout << "\n";
	cout << (p2 == 2);
	cout << "\n";
	b1.printBoard();

	// // test 3: place at a good spot
	cout << "TEST 3: PLACE O AT A GOOD SPOT \n";
	int p3 = b1.currentPlayer;
	cout << (b1.isValidPlacement(1, 0) == true);
	cout << "\n";
	cout << (b1.place(1, 0) == true);
	cout << "\n";
	cout << (p3 == 2);
	cout << "\n";
	b1.printBoard();

	// X GOES FOR THREE IN A ROW, no winner until end
	cout << "TEST 4: X goes for win" << "\n";
	cout << (b1.winner == 0);
	cout << "\n";
	cout << (b1.isGameCompleted() == false);
	cout << "\n";
	b1.place(0, 1); // X placement at (0, 1)
	b1.printBoard();
	cout << (b1.winner == 0);
	cout << "\n";
	cout << (b1.isGameCompleted() == false);
	cout << "\n";
	b1.place(1, 1); // O placement at (1, 1)
	cout << (b1.winner == 0);
	cout << "\n";
	b1.printBoard();
	b1.place(0, 2); // O placement at (1, 1)

	// CHECK WINNER, try to place at new spot, shouldn't be able to
	cout << "TEST 5: Check winner is X, try a new spot with O\n";
	cout << (b1.winner == 1);
	cout << "\n";
	cout << (b1.isGameCompleted() == true);
	cout << "\n";
	b1.printBoard();
	int p4 = b1.currentPlayer;
	cout << (p4 == 2);
	cout << "\n";
	cout << (b1.isValidPlacement(1, 2) == false);
	cout << "\n";
	cout << (b1.place(1, 2) == false);
	cout << "\n";
	b1.printBoard();


}

void testZeroGameDepth()
{
	Board b = nearCompleteGame();
	Agent a(b, 1, 2);
	int value = a.alphabeta(b, 0, -1000000, 1000000, 1);
	cout << value << "\n";
	b.place(1, 2);
	b.printBoard();
	cout << "======\n";
	cout << b.winner << "\n";
	cout << (a.player == b.winner) << "\n";
	value = a.alphabeta(b, 0, -1000000, 1000000, 1);
	cout << value << "\n";
}

void testFinalGameLowDepth()
{
	Board b = nearCompleteGame();
	Agent a(b, 1, 1);
	// int value = a.alphabeta(b, 1, -1000000, 1000000, 1);
	// cout << value << "\n";
	a.play();
	b.printBoard();

}

void testFinalGameHighDepth()
{
	Board b = nearCompleteGame();
	Agent a(b, 1, 3);
	// int value = a.alphabeta(b, 1, -1000000, 1000000, 1);
	// cout << value << "\n";
	a.play();
	b.printBoard();
}

void testOpenedGame()
{
	Board b;
	Agent a1(b, 1, 3);
	Agent a2(b, 2, 3);
	// int value = a.alphabeta(b, 1, -1000000, 1000000, 1);
	// cout << value << "\n";
	cout << "=====" << "\n";
	a1.play();
	b.printBoard();
	cout << "=====" << "\n";
	a2.play();
	b.printBoard();

	cout << "=====" << "\n";
	a1.play();
	b.printBoard();
	cout << "=====" << "\n";
	a2.play();
	b.printBoard();

	cout << "=====" << "\n";
	a1.play();
	b.printBoard();
	cout << "=====" << "\n";
	a2.play();
	b.printBoard();

}




int main() 
{
	// testSimpleGame();
	// testZeroGameDepth();
	// testFinalGameLowDepth();
	// testFinalGameHighDepth();
	testOpenedGame();
}