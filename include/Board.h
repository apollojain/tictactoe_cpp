class Board {
public:
// private:
	int board[3][3];
	int winner;
	int currentPlayer;
	bool gameCompleted;
	void changePlayer();
	void checkGameComplete();
	bool isValidPlacement(int x, int y);
// public:
	Board();
	bool place(int x, int y);
	bool isGameCompleted();
	int getItem(int x, int y);
	void setItem(int x, int y, int val);
	void printBoard();
	void play();
};